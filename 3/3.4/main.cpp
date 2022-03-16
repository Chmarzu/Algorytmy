#include <iostream>
using namespace std;

int main() {
    float a, b, suma, roznica, iloczyn, iloraz;

    cout << "Podaj dwie liczby:" << endl;
    cin >> a >> b;

    suma = a + b;
    roznica = a - b;
    iloczyn = a * b;
    if (b)
        iloraz = a / b;

    cout << "Suma: " << suma << endl << "Roznica: " << roznica << endl << "Iloczyn: " << iloczyn << endl ;
    if (b)
        cout << "Iloraz: " << iloraz;
    else
        cout << "Nie mozna obliczyc ilorazu";
    return 0;
}
