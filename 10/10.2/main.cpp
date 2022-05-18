#include <iostream>
#include <vector>

using namespace std;

int main() {
    struct prio {
        vector<string> queue;
        int elements = 0;
    } hi, med, low;

    string temp;        //pomocnicza zmienna
    char instrukcja;    //polecenie od uzytkownika
    bool loop = true;      //zapetlic
    int i, j, priority;       //liczba elementow

    cout << "Typy instrukcji:" << endl
         << "d - dodawanie napisu do kolejki" << endl
         << "u - usuwanie napisu z kolejki" << endl
         << "w - wyswietlanie zawartosci kolejki" << endl
         << "x - zamkniecie programu" << endl << endl;
    cout << "Typy priorytetow:" << endl
         << "(1) Wysoki" << endl
         << "(2) Sredni" << endl
         << "(3) Niski" << endl << endl;

    while (loop) {
        cout << "Podaj instrukcje:" << endl;    //pobranie polecenia oraz priorytetu
        cout << "$";
        cin >> instrukcja;
        if (instrukcja == 'd') {
            cout << "Podaj priorytet:" << endl;
            cout << "$";
            cin >> priority;
        }

        switch (instrukcja) {
            case 'd':   //dodawanie
                cout << "Podaj element do dodania:" << endl << "$/";
                cin >> temp;

                switch (priority) {
                    case 1:
                        hi.elements++;
                        hi.queue.push_back(temp);
                        for (i = 0; i < hi.elements; i++) {    //postepowanie w razie pustego poczatku
                            if (hi.queue[i].empty()) {
                                j = i + 1;
                                while (hi.queue[j].empty())
                                    j++;
                                hi.queue[i] = hi.queue[j];
                                hi.queue[j].pop_back();
                                i = hi.elements;
                            }
                        }
                        break;
                    case 2:
                        med.elements++;
                        med.queue.push_back(temp);
                        for (i = 0; i < med.elements; i++) {    //postepowanie w razie pustego poczatku
                            if (med.queue[i].empty()) {
                                j = i + 1;
                                while (med.queue[j].empty())
                                    j++;
                                med.queue[i] = med.queue[j];
                                med.queue[j].pop_back();
                                i = med.elements;
                            }
                        }
                        break;
                    case 3:
                        low.elements++;
                        low.queue.push_back(temp);
                        for (i = 0; i < low.elements; i++) {    //postepowanie w razie pustego poczatku
                            if (low.queue[i].empty()) {
                                j = i + 1;
                                while (low.queue[j].empty())
                                    j++;
                                low.queue[i] = low.queue[j];
                                low.queue[j].pop_back();
                                i = low.elements;
                            }
                        }
                        break;
                }

                cout << "Dodano element!" << endl;
                break;
            case 'u':   //usuwanie
                if (hi.elements) {
                    for (i = 0; i < hi.elements - 1; i++)
                        hi.queue[i] = hi.queue[i + 1];
                    hi.queue[hi.elements - 1].pop_back();
                    hi.elements--;

                    cout << "Usunieto element!" << endl;
                } else if (med.elements) {
                    for (i = 0; i < med.elements - 1; i++)
                        med.queue[i] = med.queue[i + 1];
                    med.queue[med.elements - 1].pop_back();
                    med.elements--;

                    cout << "Usunieto element!" << endl;
                } else if (low.elements) {
                    for (i = 0; i < low.elements - 1; i++)
                        low.queue[i] = low.queue[i + 1];
                    low.queue[low.elements - 1].pop_back();
                    low.elements--;

                    cout << "Usunieto element!" << endl;
                } else
                    cout << "Kolejka jest pusta!" << endl;
                break;
            case 'w':   //wyswietlanie
                if (!hi.elements && !med.elements && !low.elements)
                    cout << "Kolejka jest pusta!" << endl;
                else {
                    if (hi.elements) {
                        for (i = 0; i < hi.elements; i++) {
                            cout << hi.queue[i] << " ";
                        }
                    }
                    if (med.elements) {
                        for (i = 0; i < med.elements; i++) {
                            cout << med.queue[i] << " ";
                        }
                    }
                    if (low.elements) {
                        for (i = 0; i < low.elements; i++) {
                            cout << low.queue[i] << " ";
                        }
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