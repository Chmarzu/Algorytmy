#include <iostream>
#include <cstring>
using namespace std;

#define ROZ 51

int main() {
    char pal1[ROZ], pal2[ROZ];
    char *palin, *drom;
    int i;

    palin = &pal1[0];       //Uzupelnienie tablic pustym znakiem
    drom = &pal2[0];
    for (i = 0; i < ROZ; i++) {
        *drom = *palin = '\000';
        palin++;
        drom++;
    }

    palin = &pal1[0];       //Pobranie ciagu znakow
    cout << "Podaj ciag znakow:" << endl;
    gets(palin);

    if (pal1[ROZ-1] != '\000')      //Sprawdzenie pojemnosci
        cout << "Tablica jest za mala!";
    else {
        palin = &pal1[ROZ - 2];
        drom = &pal2[0];

        while (*palin == '\000' || *palin == '\n')      //Ustawienie wskaznika zapelnionej tablicy na pierwszy niepusty znak od konca
            palin--;

        while (palin != &pal1[0] - 1) {     //Przekopiowanie ciagu znakow w odwrotnej kolejnosci
            *drom = *palin;
            palin--;
            drom++;
        }

        palin = &pal1[0];
        drom = &pal2[0];
        if (strcmp(palin, drom) == 0)       //Wynik
            cout << "Ten ciag jest palindromem";
        else
            cout << "Ten ciag nie jest palindromem";
    }
    return 0;
}
