#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
  int los, liczba, proba = 1;

  srand(time(nullptr));
  los = rand() % 15 + 1;

  cout << "Zgadnij liczbe z przedzialu od 1 do 15" << endl;

    do {
        cout << endl << "Proba numer " << proba << endl;
        cout << "Podaj liczbe:" << endl;
        cin >> liczba;

        if (liczba == los)
            cout << "Tak! To ta liczba!" << endl;
        else {
            proba++;
            cout << "Niestety to nie ta liczba - probuj dalej!" << endl;
            if (liczba > los)
                cout << "Ta liczba jest troche za duza" << endl;
            else
                cout << "Ta liczba jest troche za mala" << endl;
        }
    } while (liczba != los);

  return 0;
}
