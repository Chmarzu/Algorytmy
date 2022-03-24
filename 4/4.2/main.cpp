#include <iostream>
#include <cmath>
using namespace std;

#define ROZ 10

void binarny (int bin[0], int *pbin, int *ppom);
int decymalny (int *pbin, const int bin[0]);

int main() {
    int pom, bin[ROZ], *pbin, liczba;

    cout << "Wybierz typ konwersji:" << endl << "(1) Dec - Bin" << endl << "(2) Bin - Dec" << endl;
    cin >> pom;     //Wybor typu konwersji

    if (pom == 1) {
        pbin = &bin[ROZ - 1];

        cout << "Podaj liczbe w systemie dziesietnym:" << endl;
        cin >> liczba;

        liczba < 0 ? liczba = -liczba : liczba;     //Ewentualna zamiana ujemnej liczby na dodatnia
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
        while (pom != '\n')     //Wyczyszczenie lancucha wejsciowego
            pom = getchar();
        do {        //Pobranie kolejnych cyfr liczby binarnej
            *pbin = getchar();
            if (*pbin != '\n') {
                *pbin -= 48;
                pbin++;
            }
        } while (*pbin != '\n' && pbin <= &bin[ROZ - 1]);

        if (pbin > &bin[ROZ - 1])
            cout << "Za duza liczba!";
        else {
            while (pbin <= &bin[ROZ - 1]) {     //Wypelnienie pustych miejsc w tablicy
                *pbin = 2;
                pbin++;
            }

            pbin = &bin[ROZ - 1];
            liczba = decymalny(pbin, &bin[0]);
            cout << "Podana liczba w systemie dziesietnym wynosi: " << liczba;
        }
    }
    return 0;
}

void binarny (int bin[0], int *pbin, int *ppom) {
    *pbin = *ppom % 2;
    *ppom = *ppom / 2;
    pbin--;

    if (*ppom && pbin >= &bin[0])       //Rekurencyjne obliczanie kolejnych cyfr postaci binarnej
        binarny(&bin[0], pbin, ppom);
    else if (pbin > &bin[0]) {      //Ewentualne uzupelnianie pustych miejsc w tablicy
        while (pbin >= &bin[0]) {
            *pbin = 2;
            pbin--;
        }
    }
}

int decymalny (int *pbin, const int bin[0]) {
    int wynik = 0, i = 0;

    while (*pbin == 2)
        pbin--;

    while (pbin >= &bin[0]) {
        if (*pbin)
            wynik += *pbin * pow(2, i);
        pbin--;
        i++;
    }

    return wynik;
}