#include <iostream>
using namespace std;

int main() {
    unsigned short mode;
    int w, j, i, a, n, det;

    cout << "Wybierz operacje:" << endl << "(1) Wyznacznik" << endl << "(2) Mnozenie macierzy" << endl << "(3) Transpozycja" << endl;
    cin >> mode;

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

     for (i = 0; i < w; i++) {
        for (j = 0; j < w; j++) {
  
           matrixSec[j][i] = matrixFirst[i][j]
        }
    }
    
  
      //cout << "Tranzpozycja macierzy pierwszej" << endl;
     // for (i = 0; i < n; i++)
      //{

             // for (j = 0; j < n; j++)
             // cout << matrixSec[j][i] <<" ";
             // cout << endl;
      // }

   

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
    }
}
