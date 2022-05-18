#include <iostream>
#include <vector>

using namespace std;

void push(vector <string> *queue, int *elements, int i);
void pop(vector <string> *queue, int *elements, int i);

int main() {
    struct prio {
        vector <string> queue;
        int elements = 0;
    } hi, med, low;

    vector <string> queue_hi, queue_med, queue_low;  //kolejka
    char instrukcja;    //polecenie od uzytkownika
    bool loop = true;      //zapetlic
    int i, elements = 0, priority;       //liczba elementow

    string temp;        //pomocnicza zmienna
    int j;

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
        cout << "Podaj instrukcje:" << endl;
        cout << "$";
        cin >> instrukcja;
        if (instrukcja != 'w' && instrukcja != 'x') {
            cout << "Podaj priorytet:" << endl;
            cout << "$";
            cin >> priority;
        }

        switch (instrukcja) {
            case 'd':   //dodawanie
                cout << "Podaj element do dodania:" << endl << "$/";
                cin >> temp;
                elements++;
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
                        queue_med.push_back(temp);
                        for (i = 0; i < elements; i++) {    //postepowanie w razie pustego poczatku
                            if (queue_med[i].empty()) {
                                j = i + 1;
                                while (queue_med[j].empty())
                                    j++;
                                queue_med[i] = queue_med[j];
                                queue_med[j].pop_back();
                                i = elements;
                            }
                        }
                        break;
                    case 3:
                        queue_low.push_back(temp);
                        for (i = 0; i < elements; i++) {    //postepowanie w razie pustego poczatku
                            if (queue_low[i].empty()) {
                                j = i + 1;
                                while (queue_low[j].empty())
                                    j++;
                                queue_low[i] = queue_low[j];
                                queue_low[j].pop_back();
                                i = elements;
                            }
                        }
                        break;
                }

                cout << "Dodano element!" << endl;

                //push(&queue_hi, &elements, i);
                break;
            case 'u':   //usuwanie
                if (elements) {
                    switch (priority) {
                        case 1:
                            for (i = 0; i < hi.elements - 1; i++)
                                hi.queue[i] = hi.queue[i + 1];
                            hi.queue[hi.elements - 1].pop_back();
                            hi.elements--;
                            break;
                        case 2:
                            for (i = 0; i < elements - 1; i++)
                                queue_med[i] = queue_med[i + 1];
                            queue_med[elements - 1].pop_back();
                            elements--;
                            break;
                        case 3:
                            for (i = 0; i < elements - 1; i++)
                                queue_low[i] = queue_low[i + 1];
                            queue_low[elements - 1].pop_back();
                            elements--;
                            break;
                    }

                    cout << "Usunieto element!" << endl;
                } else
                    cout << "Kolejka jest pusta!" << endl;

                //pop(&queue_hi, &elements, i);
                break;
            case 'w':   //wyswietlanie
                if (elements == 0)
                    cout << "Kolejka jest pusta!" << endl;
                else {
                    for (i = 0; i < elements; i++) {
                        cout << hi.queue[i] << " ";
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

void push(vector <string> *queue, int *elements, int i) {
    string temp;        //pomocnicza zmienna
    int j;

    cout << "Podaj element do dodania:" << endl << "$/";
    cin >> temp;
    (*queue).push_back(temp);
    *elements++;
    for (i = 0; i < *elements; i++) {    //postepowanie w razie pustego poczatku
        if (queue[i].empty()) {
            j = i + 1;
            while (queue[j].empty())
                j++;
            queue[i] = queue[j];
            queue[j].pop_back();
            i = *elements;
        }
    }

    cout << "Dodano element!" << endl;
}

void pop(vector <string> *queue, int *elements, int i) {
    if (*elements) {
        for (i = 0; i < *elements - 1; i++)
            queue[i] = queue[i + 1];
        queue[*elements - 1].pop_back();
        *elements--;
        cout << "Usunieto element!" << endl;
    } else
        cout << "Kolejka jest pusta!" << endl;
}