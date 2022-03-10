#include <iostream>
using namespace std;

int main() {
    unsigned short mode;
    int w, i, j, k, a, temp = 0, *pointer, *pointer2, *pointer3;

    cout << "Wybierz operacje:" << endl << "(1) Wyznacznik" << endl << "(2) Mnozenie macierzy" << endl
         << "(3) Transpozycja" << endl;
    cin >> mode;

    cout << "Podaj rozmiar dla macierzy:" << endl;
    cin >> w;
    if (w <= 0)
        cout << "Bledna wartosc!";

    int matrixFirst[w][w], matrixSec[w][w], matrixResult[w][w];

    cout << "Wypelnij macierz" << endl;
    for (i = 0; i < w; i++) {
        for (j = 0; j < w; j++) {
            cout << "Wprowadz wartosc dla elementu [" << i << "][" << j << "]:" << endl;
            cin >> a;
            matrixFirst[i][j] = a;
        }
    }

    switch (mode) {
        case 1:     //Obliczanie wyznacznika
            switch (w) {
                case 1:
                    temp = matrixFirst[0][0];
                    break;
                case 2:
                    temp = (matrixFirst[0][0] * matrixFirst[1][1]) - (matrixFirst[0][1] * matrixFirst[1][0]);
                    break;
                case 3:
                    temp = (matrixFirst[0][0] * matrixFirst[1][1] * matrixFirst[2][2]) +
                      (matrixFirst[0][1] * matrixFirst[1][2] * matrixFirst[2][0]) +
                      (matrixFirst[0][2] * matrixFirst[1][0] * matrixFirst[2][1]) -
                      (matrixFirst[0][2] * matrixFirst[1][1] * matrixFirst[2][0]) -
                      (matrixFirst[0][0] * matrixFirst[1][2] * matrixFirst[2][1]) -
                      (matrixFirst[0][1] * matrixFirst[1][0] * matrixFirst[2][2]);
                    break;
                default:
                    cout << "Blad!";
                    break;
            }
            cout << temp;
            break;
        case 2:     //Obliczanie iloczynu macierzy
            cout << "Wypelnij druga macierz" << endl;
            for (i = 0; i < w; i++) {
                for (j = 0; j < w; j++) {
                    cout << "Wprowadz wartosc dla elementu [" << i << "][" << j << "]:" << endl;
                    cin >> a;
                    matrixSec[i][j] = a;
                }
            }

            pointer3 = &matrixResult[0][0];      //Zerowanie macierzy wynikowej
            for (i = 0; i < w; i++) {       //Ustawianie pierwszej macierzy na kolejne wiersze
                for (j = 0; j < w; j++) {       //Ustawianie drugiej macierzy na kolejne kolumny
                    pointer = &matrixFirst[i][0];
                    pointer2 = &matrixSec[0][j];
                    temp = 0;
                    for (k = 0; k < w; k++) {       //Iloczyn pojedynczego wiersza i kolumny
                        temp += *pointer * *pointer2;
                        pointer++;
                        pointer2 += w;
                    }
                    *pointer3 = temp;
                    pointer3++;
                }
            }

            for (i = 0; i < w; i++) {       //Wyswietlenie wynikowej macierzy
                for (j = 0; j < w; j++) {
                    cout << matrixResult[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 3:     //Obliczanie transpozycji
            for (i = 0; i < w; i++) {       //Transpozycja
                for (j = 0; j < w; j++) {
                    matrixResult[j][i] = matrixFirst[i][j];
                }
            }

            for (i = 0; i < w; i++) {       //Wyswietlenie wynikowej macierzy
                for (j = 0; j < w; j++) {
                    cout << matrixResult[i][j] << " ";
                }
                cout << endl;
            }
            break;
        default:
            cout << "Blad!";
            break;
    }
}
