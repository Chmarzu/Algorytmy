#include <iostream>

using namespace std;

void Select(int size);
void Find(char tab[], char left[], char right[], char *pleft, char *pright, int i, int j, int k, int *r, int size, int *amount);

int main() {
    int size = 0;

    do {        //Pobranie rozmiaru tablicy sortowania
        cout << "Podaj ilosc znakow do posortowania:" << endl;
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
    int i, j, k, r, amount = 0;
    char tab[size], left[size], *pleft, right[size], *pright;
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
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (tab[i] > tab[j]) {     //Wybor pivota
                r = i;
                i = j = size;
            }
        }
    }

    for (i = 1; i < size; i++) {        //Podzial na mniejsze tablice
        if (tab[i] < tab[r]) {
            *pleft = tab[i];
            pleft++;
            amount++;
        } else {
            *pright = tab[i];
            pright++;
        }
    }

    if (amount < k)
        Find(&left[0], &left[0], &right[0], pleft, pright, i, j, k, &r, size, &amount);
    else
        Find(&right[0], &left[0], &right[0], pleft, pright, i, j, k, &r, size, &amount);
}

void Find(char tab[], char left[], char right[], char *pleft, char *pright, int i, int j, int k, int *r, int size, int *amount) {
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (tab[i] > tab[j]) {     //Wybor pivota
                *r = i;
                i = j = size;
            }
        }
    }

    for (i = 1; i < size; i++) {        //Podzial na mniejsze tablice
        if (tab[i] < tab[*r]) {
            *pleft = tab[i];
            pleft++;
            *amount++;
        } else {
            *pright = tab[i];
            pright++;
        }
    }

    if (*amount < k) {
        if (*amount == 1)
            cout << endl << tab[0];
        else
            Find(&left[0], &left[0], &right[0], pleft, pright, i, j, k, r, size, amount);
    }
    else {
        Find(&right[0], &left[0], &right[0], pleft, pright, i, j, k, r, size, amount);
        if (*amount == 1)
            cout << endl << tab[0];
    }
}