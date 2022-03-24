#include <iostream>
using namespace std;

#define ROZ 10

void binarny (int bin[0], int *pbin, int *ppom);

int main() {
    int bin[ROZ], *pbin, liczba, pom;

    cout << "Wybierz typ konwersji:" << endl << "(1) Dec - Bin" << endl << "(2) Bin - Dec" << endl;
    cin >> pom;

    if (pom == 1) {
        pbin = &bin[ROZ - 1];
        cout << "Podaj liczbe w systemie dziesietnym:" << endl;
        cin >> liczba;
        liczba < 0 ? liczba = -liczba : liczba;
        pom = liczba;
        binarny(&bin[0], pbin, &pom);
        if (pom)
            cout << "Za duza liczba!";
        else {
            pbin = &bin[0];
            cout << liczba << " w systemie binarnym: ";
            for (int i = 0; i < ROZ; i++) {
                if (*pbin < 2)
                    cout << *pbin;
                pbin++;
            }
        }
    } else {
        pbin = &bin[0];
        cout << "Podaj liczbe w systemie dwojkowym:" << endl;
        while (pom != '\n')
            pom = getchar();
        do {
            *pbin = getchar();
            if (*pbin != '\n') {
                *pbin -= 48;
                pbin++;
            }
        } while (*pbin != '\n');
        *pbin = 2;
    }
    return 0;
}

void binarny (int bin[0], int *pbin, int *ppom) {
    *pbin = *ppom % 2;
    *ppom = *ppom / 2;
    pbin--;
    if (*ppom && pbin >= &bin[0]) binarny(&bin[0], pbin, ppom);
    else if (pbin > &bin[0]) {
        while (pbin >= &bin[0]) {
            *pbin = 2;
            pbin--;
        }
    }
}