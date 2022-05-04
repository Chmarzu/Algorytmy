#include <iostream>

using namespace std;

void NumbChar(int size);
void NegNumbFloat(int size);

int main() {
    int i, size = 0, type = 0;

    do {        //Pobranie rozmiaru tablicy sortowania
        cout << "Podaj ilosc znakow do posortowania:" << endl;
        cin >> size;

        if (size < 2)
            cout << endl << "Blad!" << endl;
        cout << endl;
    } while (size < 2);

    do {        //Wybor typu sortowanych znakow
        cout << "Wypierz opcje:" << endl;
        cout << "(1) Sortowanie liczb naturalnych (dotatnie, calkowite) lub znakow" << endl;
        cout << "(2) Sortowanie liczb ujemnych lub zmiennoprzecinkowych" << endl;
        cin >> type;

        if (type == 1)
            NumbChar(size);
        else if (type == 2)
            NegNumbFloat(size);
        else
            cout << endl << "Blad!";
        cout << endl;
    } while (type != 1 && type != 2);

    cout << endl;
    fflush(stdin);
    getchar();
    return 0;
}

void NumbChar(int size) {
    int i, j, min;
    char tab[size];
    unsigned short mode;

    for (i = 0; i < size; i++) {        //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> tab[i];
    }

    do {
        cout << "Wybierz algorytm sortujacy:" << endl;
        for (i = 1; i < 6; i++) {
            switch (i) {
                case 1:
                    cout << "(" << i << ")  Sort";
                    break;
                case 2:
                    cout << "(" << i << ") Insertion Sort";
                    break;
                case 3:
                    cout << "(" << i << ") Selection Sort";
                    break;
                case 4:
                    cout << "(" << i << ") Quick Sort";
                    break;
                case 5:
                    cout << "(" << i << ") Merge Sort";
                    break;
            }
            cout << endl;
        }
        cin >> mode;
        cout << endl;
    } while (mode < 1 || mode > 5);

    switch (mode) {
        case 1:
            cout << "(" << i << ") Selection Sort";
            break;
        case 2:
            cout << "(" << i << ") Insertion Sort";
            break;
        case 3:
            cout << "(" << i << ") Selection Sort";
            break;
        case 4:
            cout << "(" << i << ") Quick Sort";
            break;
        case 5:
            cout << "(" << i << ") Merge Sort";
            break;
    }

    for (i = 0; i < size - 1; i++) {        //Sortowanie
        min = i;
        for(j = i; j < size; j++) {
            if (tab[j] < tab[min]) {
                min=j;
            }
        }
        swap(tab[min],tab[i]);
    }

    cout << endl << "Posortowana tablica:" << endl;     //Wynik
    for (i = 0; i < size; i++)
        cout << tab[i] << ' ';
}

void NegNumbFloat(int size) {
    int i, j, min;
    float tab[size];
    unsigned short mode;

    for (i = 0; i < size; i++) {        //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> tab[i];
    }

    switch (mode) {
        case 1:
            cout << "(" << i << ") Selection Sort";
            break;
        case 2:
            cout << "(" << i << ") Insertion Sort";
            break;
        case 3:
            cout << "(" << i << ") Selection Sort";
            break;
        case 4:
            cout << "(" << i << ") Quick Sort";
            break;
        case 5:
            cout << "(" << i << ") Merge Sort";
            break;
    }

    for (i = 0; i < size - 1; i++) {        //Sortowanie
        min = i;
        for(j = i; j < size; j++) {
            if (tab[j] < tab[min]) {
                min=j;
            }
        }
        swap(tab[min],tab[i]);
    }

    cout << endl << "Posortowana tablica:" << endl;     //Wynik
    for (i = 0; i < size; i++)
        cout << tab[i] << ' ';
}