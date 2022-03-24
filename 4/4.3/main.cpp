#include <iostream>
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
        int inputVariable, temp, n, m = 0, i;
        char ANSWER[12], SIGILS[16] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        char *pANS;
        pANS = &ANSWER[11];

        cout << "Podaj liczbe:";
        cin >> inputVariable;
        temp = inputVariable;

        do
        {
            n = temp % 16;
            temp = temp / 16;
            *pANS = SIGILS[n];
            if (temp != 0)
                pANS--;
        }
        while (temp != 0);

        cout << "0x";
        while (pANS <= &ANSWER[11]) {
            cout << *pANS;
            pANS++;
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