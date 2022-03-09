#include <iostream>
using namespace std;
int w, j,i, a;
int main() {
    cout << "Podaj rozmiar dla wspólnych macierzy";
    cin >> w;

    int matrixFirst[w][w], matrixSec[w][w];
    cout << "Wypisz liczby dla macierzy pierwszej od lewej do prawej" << endl;

    for (i = 0; i < w; i++) {
        for (j = 0; j < w; j++) {
            cin >> a;
            matrixFirst[i][j] = a;
        }
    }
}