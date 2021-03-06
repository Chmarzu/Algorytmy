#include <iostream>

using namespace std;


int main() {

    int i, j, size, mode;

    do {
        cout << "Podaj ilosc znakow do posortowania:" << endl;      //Okreslenie ilosci znakow
        cin >> size;
    } while (size < 2);
    char tabc[size];
    float tabf[size];

    do {
        cout << endl << "Wypierz opcje:" << endl;       //Okreslenie typu znakow
        cout << "(1) Sortowanie liczb naturalnych (dotatnie, calkowite) lub znakow" << endl;
        cout << "(2) Sortowanie liczb ujemnych lub zmiennoprzecinkowych" << endl;
        cin >> mode;
    } while (mode != 1 && mode != 2);
    cout << endl;

    switch (mode) {
        case 1:
            for (i = 0; i < size; i++) {
                cout << "Podaj element numer " << i + 1 << ":" << endl;
                cin >> tabc[i];
            }

            for (i = 0; i < size; i++) {
                for (j = 1; j < size; j++) {
                    if (tabc[j - 1] > tabc[j])
                        swap(tabc[j - 1], tabc[j]);
                }
            }

            cout << endl << "Posortowana tablica:" << endl;
            for (i = 0; i < size; i++)
                cout << tabc[i] << ' ';
            break;
        case 2:
            for (i = 0; i < size; i++) {
                cout << "Podaj element numer " << i + 1 << ":" << endl;
                cin >> tabf[i];
            }

            for (i = 0; i < size; i++) {
                for (j = 1; j < size; j++) {
                    if (tabf[j - 1] > tabf[j])
                        swap(tabf[j - 1], tabf[j]);
                }
            }

            cout << endl << "Posortowana tablica:" << endl;
            for (i = 0; i < size; ++i)
                cout << tabf[i] << ' ';
            break;
        default:
            cout << "Bledna wartosc!";
            break;
    }

    cout << endl;
    fflush(stdin);
    getchar();

    return 0;
}