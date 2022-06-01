#include <iostream>
#include <fstream>

using namespace std;

int partition(int arr[], int a, int b);

int main() {
    int n = 100;      //liczba elementow
    int k = 1;      //poszukiwany element
    int i = 0, j = 0, w;       //pomocnicze zmienne
    int arr[n];   //zbior elementow
    fstream file;   //wskaznik obslugujacy plik
    string line;    //pomocnicza zmienna
    clock_t diff[3] = {0, 0, 0};    //wartosci czasu: poczatek, koniec, roznica

    file.open("src1.txt");
    while (file.good()) {
        getline(file, line);

        while (j < 3 && line[j] != '\0') {
            if (!j)
                arr[i] = line[j] - 48;
            else
                arr[i] = arr[i] * 10 + line[j] - 48;
            j++;
        }

        i++;
        j = 0;
    }
    file.close();

    diff[0] = clock();

        //Algorytm Hoare'a
        i = 0;
        j = n - 1;
        n = k;

        while (i != j) {
            w = partition(arr, i, j);   //Podzial na podzbiory
            w = w - i + 1;
            if (w >= k) j = i + w - 1;
            if (w < k) {
                k -= w;
                i += w;
            }
        }

    diff[1] = clock();
    diff[2] = diff[1] - diff[0];

        cout << endl << "Poszukiwany " << n << ". element to: " << arr[i];
        cout << endl << diff[2];

    cout << endl;
    fflush(stdin);
    getchar();

    return 0;
}

int partition(int arr[], int a, int b) {
    int e;      //elemennt dzielacy

    e = arr[a];
    while (a < b) {
        while (a < b && arr[b] >= e)
            b--;
        while (a < b && arr[a] < e)
            a++;
        if (a < b)
            swap(arr[a], arr[b]);
    }
    return a;
}