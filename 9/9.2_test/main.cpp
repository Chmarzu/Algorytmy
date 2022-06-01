#include<iostream>
#include <fstream>

using namespace std;

int selection(int arr[], int l, int r, int n, int k, int i);
int calc_median(int arr[], int n, int i);
int partition(int arr[], int l, int r, int x, int i);

int main() {
    int n = 100;      //liczba elementow
    int k = 1;      //poszukiwany element
    int arr[n];   //zbior elementow
    int i = 0, j = 0;       //pomocnicza zmienna
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

    cout << endl << "Poszukiwany " << k << ". element to: "
         << selection(arr, 0, n - 1, n, k, i);

    diff[1] = clock();
    diff[2] = diff[1] - diff[0];
    cout << endl << diff[2];

    return 0;
}

int selection(int arr[], int l, int r, int n, int k, int i) {
    int median[(n + 4) / 5];    //tablica z medianami
    int MedOfMed;   //mediana wszystkich median
    int pos;    //liczba elementow w podzbiorze

    n = r - l + 1;

    //Obliczanie median
    for (i = 0; i < n / 5; i++)
        median[i] = calc_median(arr + l + i * 5, 5, i);
    if (i * 5 < n) {
        median[i] = calc_median(arr + l + i * 5, n % 5, i);
        i++;
    }

    //Obliczanie mediany wszystkich median
    MedOfMed = (i == 1) ? median[i - 1] :
            selection(median, 0, i - 1, n, i / 2, i);

    pos = partition(arr, l, r, MedOfMed, i);   //Podzial zbioru na podzbior

    if (pos - l == k - 1)      //Jesli podzbior jest rowny poszukiwanemu elementowi
        return arr[pos];
    if (pos - l > k - 1) //Jesli podzbior jest mniejszy od k
        return selection(arr, l, pos - 1, n, k, i);
    else    //Jesli podzbior jest wiekszy od k
        return selection(arr, pos + 1, r, n, k - pos + l - 1, i);
}

int calc_median(int arr[], int n, int i) {
    int j;       //pomocnicza zmienna

    for (i = 0; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }

    return arr[n/2];
}

int partition(int arr[], int l, int r, int x, int i) {
    int j;       //pomocnicza zmienna

    for (i = l; i < r; i++)     //Wybor pivota
        if (arr[i] == x)
            break;
    swap(arr[i], arr[r]);

    i = l;      //Podzial na podzbior
    for (j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);

    return i;
}