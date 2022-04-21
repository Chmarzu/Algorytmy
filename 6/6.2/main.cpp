#include <iostream>

using namespace std;

void NumbChar(int size);
void NegNumbFloat(int size);

int main() {
    int size = 0, mode = 0;

    do {
        cout << "Podaj ilosc znakow do posortowania:" << endl;
        cin >> size;

            if (size < 2)
                cout << endl << "Blad!" << endl;
        cout << endl;
    } while (size < 2);

    do {
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
    int i, j, avg = 0, sub[size], lesser = '\0', greater = '\0';
    char tab[size], *ptab, pivot, left[size], *pleft, right[size], *pright;
    ptab = &tab[0];
    pleft = &left[0];
    pright = &right[0];

    for (i = 0; i < size; i++) {
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> tab[i];
        left[i] = right[i] = '\0';
        //avg += tab[i];
    }

    /*
    avg /= size;
    for (i = 0; i < size; i++) {
        sub[i] = avg - tab[i];
        sub[i] < 0 ? sub[i] = -sub[i]: sub[i];
    }
    for (i = 0; i < size; i++) {

    }


    do {
        for (i = 0; i < size; ++i) {

        }
    } while (lesser == '\0' || greater == '\0')
    */

    pivot = tab[0];

    for (i = 1; i < size; i++) {
        if (tab[i] < pivot) {
            *pleft = tab[i];
            pleft++;
        } else {
            *pright = tab[i];
            pright++;
        }
    }

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
                if (right[j - 1] > right[j] && left[j] != '\0')
                    swap(right[j - 1], right[j]);
            }
        }
    }

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

    cout << endl << "Posortowana tablica:" << endl;
    for (i = 0; i < size; i++)
        cout << tab[i] << ' ';
}

void NegNumbFloat(int size) {
    int i, j;
    float tab[size], *ptab, pivot, left[size], *pleft, right[size], *pright;
    ptab = &tab[0];
    pleft = &left[0];
    pright = &right[0];

    for (i = 0; i < size; i++) {
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> tab[i];
        left[i] = right[i] = '\0';
    }

    pivot = tab[0];
    for (i = 1; i < size; i++) {
        if (tab[i] < pivot) {
            *pleft = tab[i];
            pleft++;
        } else {
            *pright = tab[i];
            pright++;
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (left[j - 1] > left[j] && left[j] != '\0')
                swap(left[j - 1], left[j]);
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (right[j - 1] > right[j]  && left[j] != '\0')
                swap(right[j - 1], right[j]);
        }
    }
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

    cout << endl << "Posortowana tablica:" << endl;
    for (i = 0; i < size; i++)
        cout << tab[i] << ' ';
}