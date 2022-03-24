//
// Created by shenglz on 24.03.2022.
//

//
// Created by shenglz, Chmarzu on 24.03.2022.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{

    int choice;

    cout << "CO ROBIMY? ZAMIENIAMY Z SZESNASTKOWEGO NA DZIESIĘTNY, CZY NA ODWRÓT?" << endl;
    cout << "Z DZIESIĘTNEGO NA SZESNASTKOWY - WPISZ 1" << endl;
    cout << "Z SZESNASTKOWEGO NA DZIESIĘTNY - WPISZ 2" << endl;
    cin >> choice;

    if (choice == 1)
    {
        int inputVariable, temp, n,m,i;
        char ANSWER[12], SIGILS[16] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

        cout << "Dawaj jakąś liczbe:";
        cin >> inputVariable;
        temp = inputVariable;

        do
        {
            n = temp % 16;
            temp = temp / 16;
            ANSWER[m] = SIGILS[n];
            m += 1;
        }
        while (temp != 0);

        for (int i = 0; i < 12; ++i) {
            cout << ANSWER[i];

        }

        cout << endl;
    }
    else if  (choice == 2)
    {
    }
    else
    {
        cout << "BŁĄD!!! WPROWADZONY WYBÓR JEST NIE PRAWIDŁOWY" << endl;
        main();
    }

    return 0;
}