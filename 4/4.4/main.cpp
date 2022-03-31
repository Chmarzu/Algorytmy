#include <iostream>
#include <cstring>
using namespace std;

int main() {

    int i = 0, nr = 1, pom = 0, pom2 = 0;
    float waga = 0, liczba = 0, srednia;
    char stop[5], *pstop;
    pstop = &stop[0];
    stop[i] = '\000';       //Czyszczenie lancucha

    cout << "Program do obliczania sredniej." << endl;

    do {        //Wczytanie liczb i wag
        cout << "Podaj liczbe numer " << nr << endl;
        cin >> pom;

        cout << "Podaj wage numer " << nr++ << endl;
        cin >> pom2;
        waga += pom2;
        liczba += pom * pom2;

        cout << "Wcisnij ENTER, aby dodac kolejne wartosci." << endl << "Wpisz STOP aby przejsc do obliczania sredniej." << endl;
        fflush(stdin);
        fgets(pstop, 5, stdin);
    } while (strcmp(stop, "STOP") != 0);

    srednia = liczba / waga;
    cout << "Srednia wazona z podanych liczb wynosi: " << srednia;
    return 0;
}