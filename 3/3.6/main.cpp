#include <iostream>
using namespace std;

int main() {
    float a1, a2, b1, b2, c1, c2, W, Wx, Wy, x, y;

    cout << "Podaj wspolczynniki pierwszego rownania:" << endl;
    cin >> a1 >> b1 >> c1;
    cout << "Podaj wspolczynniki drugiego rownania:" << endl;
    cin >> a2 >> b2 >> c2;

    W = a1 * b2 - b1 * a2;      //Obliczanie wyznacznikow
    Wx = c1 * b2 - b1 * c2;
    Wy = a1 * c2 - c1 * a2;

    if(W != 0) {
        cout << "x = "<< Wx / W << endl;
        cout << "y = "<< Wy / W << endl;
    } else {
        if (Wx == 0 && Wy == 0)
            cout << "Uklad nieoznaczony" << endl;
        else
            cout << "Uklad sprzeczny" << endl;
    }
    return 0;
}
