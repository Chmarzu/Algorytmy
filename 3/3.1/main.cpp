#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float triangle[3], temp, perimeter, field;
    int i, j;

    for (i = 0; i < 3; i++) {       //Pobranie wymiarow trojkata
        cout << "Podaj dlugosc " << i + 1 << " boku:" << endl;
        cin >> triangle[i];
    }

    for (i = 0; i < 3; i++) {       //Sortowanie metoda sortowania babelkowego dla odnalezienia najdluzszego boku
        for (j = i + 1; j < 3; j++) {
            if (triangle[i] > triangle[j]) {
                temp = triangle[i];
                triangle[i] = triangle[j];
                triangle[j] = temp;
            }
        }
    }

    if (triangle[2] < triangle[0] + triangle[1]) {      //Sprawdzenie, czy mozna utworzyc trojkat
        perimeter = triangle[0] + triangle[1] + triangle[2];        //Obliczanie obwodu
        cout << "Obwod tego trojkaka wynosi: " << perimeter << endl;

        temp = perimeter / 2;       //Obliczanie pola
        field = sqrt(temp * (temp - triangle[0]) * (temp - triangle[1]) * (temp - triangle[2]));
        cout << "Pole tego trojkata wynosi: " << field << endl;
    } else cout << "Nie mozna utworzyc trojkata!";

    return 0;
}
