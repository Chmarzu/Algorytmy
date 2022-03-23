#include <iostream>
using namespace std;

int main() {
    int liczba, i;
    do {        //Pobranie wartosci od uzytkownika we wlasciwym przedziale
        cout << "Podaj liczbe:" << endl;
        cin >> liczba;
        if (liczba <= 1)
            cout << "Bledna wartosc!" << endl;
    } while (liczba <= 1);

    for (i = 2; i < liczba; i++) {      //Sprawdzenie pierwszosci liczby
        if (liczba % i == 0) {
            cout << "Ta liczba nie jest liczba pierwsza";
            break;
        }
    }

    if (i == liczba)
        cout << "Ta liczba jest liczba pierwsza";
    return 0;
}
