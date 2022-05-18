#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <string> queue;  //kolejka
    string temp;        //pomocnicza zmienna
    char instrukcja;    //polecenie od uzytkownika
    bool loop = true;      //zapetlic
    int i, j, elements = 0;       //liczba elementow

    cout << "Podaj instrukcje:" << endl
    << "d - dodawanie napisu do kolejki" << endl
    << "u - usuwanie napisu z kolejki" << endl
    << "w - wyswietlanie zawartosci kolejki" << endl
    << "x - zamkniecie programu" << endl << endl;

    while (loop) {
        cout << "$";
        cin >> instrukcja;
        switch (instrukcja) {
            case 'd':   //dodawanie
                cout << "Podaj element do dodania:" << endl << "$/";
                cin >> temp;
                queue.push_back(temp);
                elements++;
                for (i = 0; i < elements; i++) {    //postepowanie w razie pustego poczatku
                    if (queue[i].empty()) {
                        j = i + 1;
                        while (queue[j].empty())
                            j++;
                        queue[i] = queue[j];
                        queue[j].pop_back();
                        i = elements;
                    }
                }

                cout << "Dodano element!" << endl;
                break;
            case 'u':   //usuwanie
                if (elements) {
                    for (i = 0; i < elements - 1; i++)
                        queue[i] = queue[i + 1];
                    queue[elements - 1].pop_back();
                    elements--;
                    cout << "Usunieto element!" << endl;
                } else
                    cout << "Kolejka jest pusta!" << endl;
                break;
            case 'w':   //wyswietlanie
                if (elements == 0)
                    cout << "Kolejka jest pusta!" << endl;
                else {
                    for (i = 0; i < elements; i++) {
                        cout << queue[i] << " ";
                    }
                    cout << endl;
                }
                break;
            case 'x':   //wyjscie
                loop = false;
                break;
            default:
                cout << "Taka instrukcja nie istnieje!" << endl;
                break;
        }
    }
    return 0;
}
