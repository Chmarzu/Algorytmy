#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float tab[3], pom, s, field;
    int i, j;

    for(i = 0; i < 3; i++) {
        cout << "Podaj długosc " << i + 1 << " boku:" << endl;
        cin >> tab[i];
    }

    for(i = 0; i < 3; i++){
        for (j = i + 1; j < 3; j++) {
            if (tab[i] > tab[j]) {
                pom = tab[i];
                tab[i] = tab[j];
                tab[j] = pom;
            }
        }
    }

    if(tab[2] < tab[0] + tab[1]) {
        cout << "Obwod tego trojkaka wynosi: " << tab[0] + tab[1] + tab[2] << endl;
        s = (tab[0] + tab[1] + tab[2])/2;
        field = sqrt(s * (s - tab[0]) * (s - tab[1]) * (s - tab[2]));
        cout << "Pole tego trojkata wynosi: " << field << endl;
    } else cout << "Nie mozna utworzyc trojkata!";

}
