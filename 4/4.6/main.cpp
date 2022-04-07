#include <iostream>

using namespace std;

#define ROZ 11

int main() {
    char pesel[ROZ];
    int i, suma = 0, wynik;

    cout << "Podaj numer PESEL:" << endl;       //Pobranie PESEL-u
    for (i = 0; i < ROZ; i++) {
        cin >> pesel[i];
        if (pesel[i] < 48 || pesel[i] > 57) {       //Weryfikacja wprowadzonych wartosci
            cout << "Nieprawidlowy PESEL.";
            exit(0);
        }
    }

    for (i = 0; i < ROZ; i++) {     //Test PESEL-u
        if (!i || i == 4 || i == 8 || i == 10)
            suma += (pesel[i]  - 48) * 1;
        else if (i == 1 || i == 5 || i == 9)
            suma += (pesel[i]  - 48) * 3;
        else if (i == 2 || i == 6)
            suma += (pesel[i]  - 48) * 7;
        else if (i == 3 || i == 7)
            suma += (pesel[i]  - 48) * 9;
    }
    wynik = suma % 10;

    if (!wynik)
        cout << "Prawidlowy PESEL."  << endl;
    else
        cout << "Nieprawidlowy PESEL." << endl;
    fflush(stdin);
    getchar();
    return 0;
}