#include <iostream>
using namespace std;

int main() {
    unsigned short mode;
    int w, i, j, k, a, det, *pointer, *pointer2, *pointer3, pom = 0;

    cout << "Wybierz operacje:" << endl << "(1) Wyznacznik" << endl << "(2) Mnozenie macierzy" << endl
         << "(3) Transpozycja" << endl;
    cin >> mode;

    cout << "Podaj rozmiar dla wspólnych macierzy";
    cin >> w;

    int matrixFirst[w][w], matrixSec[w][w], matrixMulti[w][w];
    cout << "Wypisz liczby dla macierzy pierwszej od lewej do prawej" << endl;

    for (i = 0; i < w; i++) {
        for (j = 0; j < w; j++) {
            cin >> a;
            matrixFirst[i][j] = a;
        }
    }

    switch (mode) {
        case 1:
            if (w == 2)
                det = (matrixFirst[0][0] * matrixFirst[1][1]) - (matrixFirst[0][1] * matrixFirst[1][0]);
            else if (w == 3) {
                det = (matrixFirst[0][0] * matrixFirst[1][1] * matrixFirst[2][2]) +
                      (matrixFirst[0][1] * matrixFirst[1][2] * matrixFirst[2][0]) +
                      (matrixFirst[0][2] * matrixFirst[2][0] * matrixFirst[2][1]) -
                      (matrixFirst[0][2] * matrixFirst[1][1] * matrixFirst[2][0]) -
                      (matrixFirst[0][0] * matrixFirst[1][2] * matrixFirst[2][1]) -
                      (matrixFirst[0][1] * matrixFirst[1][0] * matrixFirst[2][2]);
            }
            cout << det;
            break;
        case 2:
            cout << "Wypisz liczby dla macierzy drugiej od lewej do prawej" << endl;

            for (i = 0; i < w; i++) {
                for (j = 0; j < w; j++) {
                    cin >> a;
                    matrixSec[i][j] = a;
                }
            }

            pointer3 = &matrixMulti[0][0]; //zeruje matryce wynikową
            for (k = 0; k < w; ++k) { //ustwia pierwszą macierz do mnożenia tak żeby przesuwać się po wierszach
                for (j = 0; j < w; j++) { //ustwia drugą macierz tak żeby przesuwać się po kolumach
                    pointer = &matrixFirst[k][0];
                    pointer2 = &matrixSec[0][j];
                    pom = 0; 
                    for (i = 0; i < w; ++i) { //przemnaża pojedyńczy wiersz i kolumne
                        pom += *pointer * *pointer2;
                        pointer++;
                        pointer2 += w;
                    }
                    *pointer3 = pom;
                    pointer3++;
                }
            }

            for (i = 0; i < w; i++) {
                for (j = 0; j < w; j++) {
                    cout << matrixMulti[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 3:
            for (i = 0; i < w; i++) {
                for (j = 0; j < w; j++) {
                    matrixSec[j][i] = matrixFirst[i][j];
                }
            }

            for (i = 0; i < w; i++) {
                for (j = 0; j < w; j++) {
                    cout << matrixSec[i][j];
                }
                cout << endl;
            }
            break;
    }
}
