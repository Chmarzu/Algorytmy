#include <iostream>
using namespace std;

int main() {
    int n, liczba1 = 0, liczba2 = 1;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Bledne wartosci!");
        return 0;
    }
    else if (n == 0) printf("Element ciagu Fibonacciego: %d", liczba1);
    else if (n == 1 || n == 2) printf("Element ciagu Fibonacciego: %d", liczba2);
    else {
        for (int i = 0; i < n - 2; ++i) {
            liczba1 = liczba2;
            liczba2 += liczba1;
        }
        printf("Element ciagu Fibonacciego: %d", liczba2);
    }
    return 0;
}
