#include <iostream>
using namespace std;
int w, j,i, a;
int main() {
    cout << "Podaj rozmiar dla wspólnych macierzy";
    cin >> w;

    int matrixFirst[w][w], matrixSec[w][w];
    cout << "Wypisz liczby dla macierzy pierwszej od lewej do prawej" << endl;

    for (i = 0; i < w; i++)
    {
        for (j = 0; j < w; j++) 
        {
            cin >> a;
            matrixFirst[i][j] = a;
        }
    }
    
    cout << "Tranzpozycja macierzy pierwszej" << endl;
    for (i = 0; i < n; i++) {
        
            for (j = 0; j < n; j++)
            cout << matFirst[j][i] <<" ";
            cout << endl;
}
