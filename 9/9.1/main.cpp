#include <iostream>

using namespace std;

void Select(int size);
void Find(int tab[], int left[], int right[], int *pleft, int *pright, int i, int j, int k, int *r, int size, int *amount);

int main() {
    int size = 0;

    do {        //Pobranie rozmiaru tablicy sortowania
        cout << "Podaj rozmiar zbioru:" << endl;
        cin >> size;

            if (size < 1)
                cout << endl << "Blad!" << endl;
        cout << endl;
    } while (size < 1);

    Select(size);

    cout << endl;
    fflush(stdin);
    getchar();

    return 0;
}

void Select(int size) {
    int i, j;       //zmienne petli
    int k;      //indeks poszukiwanego elementu
    int *r;     //element dzielacy
    int amount = 0;     //liczba elementow mniejszych od elementu dzielacego
    int tab[size];      //poczatkowa tablica
    int left[size], *pleft, right[size], *pright;       //pomniejszcze zbiory

    pleft = &left[0];
    pright = &right[0];

    for (i = 0; i < size; i++)
        tab[size] = '\0';

    for (i = 0; i < size; i++) {        //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> tab[i];
        left[i] = right[i] = '\0';
    }

    if (size == 1)
        cout << endl << tab[0];
    else {
        cout << "Podaj indeks poszukiwanego elementu:" << endl;
        cin >> k;

        for (i = 0; i < size; i++) {
            for (j = i + 1; j < size; j++) {
                if (tab[i] > tab[j]) {     //Wybor pivota
                    r = &tab[i];
                    i = j = size;
                }
            }
        }

        for (i = 0; i < size; i++) {        //Podzial na mniejsze tablice
            if (tab[i] < *r) {
                *pleft = tab[i];
                pleft++;
                amount++;
            } else {
                *pright = tab[i];
                pright++;
            }
        }

        if (amount < k)     //Wybor zbioru do kolejnego podzialu
            Find(&left[0], &left[0], &right[0], pleft, pright, i, j, k, r, size, &amount);
        else
            Find(&right[0], &left[0], &right[0], pleft, pright, i, j, k, r, size, &amount);
    }
}

void Find(int tab[], int left[], int right[], int *pleft, int *pright, int i, int j, int k, int *r, int size, int *amount) {
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (tab[i] > tab[j]) {     //Wybor pivota
                *r = tab[i];
                i = j = size;
            }
        }
    }

    for (i = 0; i < size; i++) {        //Podzial na mniejsze tablice
        if (tab[i] < *r) {
            *pleft = tab[i];
            pleft++;
            *amount++;
        } else {
            *pright = tab[i];
            pright++;
        }
    }

    if (*amount < k) {      //Wybor zbioru do kolejnego podzialu
        if (*amount == 1)
            cout << endl << tab[0];
        else
            Find(&left[0], &left[0], &right[0], pleft, pright, i, j, k, r, size, amount);
    } else {
        if (*amount == 1)
            cout << endl << tab[0];
        else
            Find(&right[0], &left[0], &right[0], pleft, pright, i, j, k, r, size, amount);
    }
}