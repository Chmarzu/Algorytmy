#include <iostream>
using namespace std;

int main() {
    int n = -1, i, liczba1 = 0, liczba2 = 1, wynik;

    while (n < 0) {
        cout << "Podaj liczbe:" << endl;
        cin >> n;
        if (n < 0)
            cout << "Bledne wartosci!" << endl;
    }

    cout << "Element ciagu Fibonacciego: ";
    if (!n)
        cout << liczba1;
    else if (n == 1 || n == 2)
        cout << liczba2;
    else {
        liczba1 = liczba2;
        for (i = 0; i < n - 2; i++) {
            wynik = liczba1 + liczba2;
            if (n > 3) {
                liczba1 = liczba2;
                liczba2 = wynik;
            }
        }
        cout << "Element ciagu Fibonacciego: " << wynik;
    }
    return 0;
}
