#include <iostream>

using namespace std;

void NumbChar(int size);
void NegNumbFloat(int size);

int main() {
    int size = 0, mode = 0;

    do {        //Pobranie rozmiaru tablicy sortowania
        cout << "Podaj ilosc znakow do posortowania:" << endl;
        cin >> size;

            if (size < 1)
                cout << endl << "Blad!" << endl;
        cout << endl;
    } while (size < 1);

    do {        //Wybor typu sortowanych znakow
        cout << "Wypierz opcje:" << endl;
        cout << "(1) Sortowanie liczb naturalnych (dotatnie, calkowite) lub znakow" << endl;
        cout << "(2) Sortowanie liczb ujemnych lub zmiennoprzecinkowych" << endl;
        cin >> mode;

            if (mode == 1)
                NumbChar(size);
            else if (mode == 2)
                NegNumbFloat(size);
            else
                cout << endl << "Blad!";
        cout << endl;
    } while (mode != 1 && mode != 2);

    cout << endl;
    fflush(stdin);
    getchar();

    return 0;
}

void NumbChar(int size) {
    int i, j, k;
    char tab[size], *ptab, pivot, left[size], *pleft, right[size], *pright;
    ptab = &tab[0];
    pleft = &left[0];
    pright = &right[0];

    for (i = 0; i < size; i++)
        tab[size] = '\0';

    for (i = 0; i < size; i++) {        //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> tab[i];
        left[i] = right[i] = '\0';
    }

    if (size == 1) {
        cout << endl << tab[0];

        cout << endl;
        fflush(stdin);
        getchar();

        exit(0);
    } else {
        cout << "Podaj wartosc poszukiwanego elementu:" << endl;
        cin >> k;
    }

             pivot = tab[0];     //Wybor pivota

    for (i = 1; i < size; i++) {        //Podzial na mniejsze tablice
        if (tab[i] < pivot) {
            *pleft = tab[i];
            pleft++;
        } else {
            *pright = tab[i];
            pright++;
        }
    }

    //Sortowanie mniejszych tablic
    if (left[0] != '\0') {
        for (i = 0; i < size; i++) {
            for (j = 1; j < size; j++) {
                if (left[j - 1] > left[j] && left[j] != '\0')
                    swap(left[j - 1], left[j]);
            }
        }
    }

    if (right[0] != '\0') {
        for (i = 0; i < size; i++) {
            for (j = 1; j < size; j++) {
                if (right[j - 1] > right[j] && right[j] != '\0')
                    swap(right[j - 1], right[j]);
            }
        }
    }

    //Przeniesienie posortowanych elementow do glownej tablicy
    pleft = &left[0];
    while (*pleft != '\0') {
        *ptab = *pleft;
        ptab++;
        pleft++;
    }

    *ptab = pivot;
    ptab++;

    pright = &right[0];
    while (*pright != '\0') {
        *ptab = *pright;
        ptab++;
        pright++;
    }

    cout << endl << "Posortowana tablica:" << endl;     //Wynik
    for (i = 0; i < size; i++)
        cout << tab[i] << ' ';
}

void NegNumbFloat(int size) {
    int i, j;
    float tab[size], *ptab, pivot, left[size], *pleft, right[size], *pright;
    ptab = &tab[0];
    pleft = &left[0];
    pright = &right[0];

    for (i = 0; i < size; i++) {        //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> tab[i];
        left[i] = right[i] = '\0';
    }

    pivot = tab[0];     //Wybor pivota

    for (i = 1; i < size; i++) {        //Podzial na mniejsze tablice
        if (tab[i] < pivot) {
            *pleft = tab[i];
            pleft++;
        } else {
            *pright = tab[i];
            pright++;
        }
    }

    //Sortowanie mniejszych tablic
    for (i = 0; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (left[j - 1] > left[j] && left[j] != '\0')
                swap(left[j - 1], left[j]);
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (right[j - 1] > right[j]  && right[j] != '\0')
                swap(right[j - 1], right[j]);
        }
    }

    //Przeniesienie posortowanych elementow do glownej tablicy
    pleft = &left[0];
    while (*pleft != '\0') {
        *ptab = *pleft;
        ptab++;
        pleft++;
    }

    *ptab = pivot;
    ptab++;

    pright = &right[0];
    while (*pright != '\0') {
        *ptab = *pright;
        ptab++;
        pright++;
    }

    cout << endl << "Posortowana tablica:" << endl;     //Wynik
    for (i = 0; i < size; i++)
        cout << tab[i] << ' ';
}