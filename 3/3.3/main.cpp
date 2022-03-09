#include <iostream>
using namespace std;

int main() {
    int n, i, liczba1 = 0, liczba2 = 1, wynik;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Bledne wartosci!");
        exit(0);
    }
    else if (!n) printf("Element ciagu Fibonacciego: %d", liczba1);
    else if (n == 1 || n == 2) printf("Element ciagu Fibonacciego: %d", liczba2);
    else {
        liczba1 = liczba2;
        for (i = 0; i < n - 2; i++) {
            wynik = liczba1 + liczba2;
            if (n > 3) {
                liczba1 = liczba2;
                liczba2 = wynik;
            }
        }
        printf("Element ciagu Fibonacciego: %d", liczba2);
    }
    return 0;
}
