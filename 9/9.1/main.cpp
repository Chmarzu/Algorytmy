#include <iostream>

using namespace std;

int partition(int arr[], int a, int b);

int main() {
    int n = 0;      //liczba elementow
    int k;      //poszukiwany element
    int i, j, w;       //pomocnicze zmienne

    do {        //Pobranie rozmiaru tablicy sortowania
        cout << "Podaj rozmiar zbioru:" << endl;
        cin >> n;

        if (n < 1)
            cout << endl << "Blad!" << endl;
        cout << endl;
    } while (n < 1);

    int arr[n];   //zbior elementow

    for (i = 0; i < n; i++) {       //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> arr[i];
    }

    if (n == 1)
        cout << endl << "Poszukiwany element to: " << arr[0];
    else {
        do {
            cout << "Podaj indeks poszukiwanego elementu:" << endl;
            cin >> k;

            if (k > n || k < 1)
                cout << endl << "Nie ma takiego elementu!";
        } while (k > n || k < 1);

        //Algorytm Hoare'a
        i = 0;
        j = n - 1;
        n = k;

        while (i != j) {
            w = partition(arr, i, j);
            w = w - i + 1;
            if (w >= k) j = i + w - 1;
            if (w < k) {
                k -= w;
                i += w;
            }
        }

        cout << endl << "Poszukiwany " << n << ". element to: " << arr[i];
    }

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