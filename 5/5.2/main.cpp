#include <iostream>

using namespace std;


int main() {

    int i, j, size, mode;

    do {
        cout << "Podaj ilosc znakow do posortowania:" << endl;      //Okreslenie ilosci znakow
        cin >> size;
    } while (size < 2);
    char notsortc[size], sortc[size];
    float notsortf[size], sortf[size];

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
                cin >> notsortc[i];
            }

            sortc[0] = notsortc[0];
            for (i = 1; i < size; i++) {
                sortc[i] = notsortc[i];
                for (j = 0; j < size; j++) {
                    if (sortc[j] > sortc[i])
                        swap(sortc[j], sortc[i]);
                }
            }

            cout << endl << "Posortowana tablica:" << endl;
            for (i = 0; i < size; i++)
                cout << sortc[i] << ' ';
            break;
        case 2:
            for (i = 0; i < size; i++) {
                cout << "Podaj element numer " << i + 1 << ":" << endl;
                cin >> notsortf[i];
            }

            sortf[0] = notsortf[0];
            for (i = 1; i < size; i++) {
                sortf[i] = notsortf[i];
                for (j = 0; j < size; j++) {
                    if (sortf[j] > sortf[i])
                        swap(sortf[j], sortf[i]);
                }
            }

            cout << endl << "Posortowana tablica:" << endl;
            for (i = 0; i < size; i++)
                cout << sortf[i] << ' ';

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