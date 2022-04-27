#include <iostream>

using namespace std;

int main() {
    int i, j, size, temp;

    cout << "Podaj liczbe elementow do posortowania:" << endl;
    cin >> size;

    temp = size / 2;

    int array[size], A[temp], B[size - temp], *a, *b;
    a = &A[0];
    b = &B[0];

    for (i = 0; i < size; i++) {
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> array[i];
        if (i < temp) {
            *a = array[i];
            a++;
    }
        else {
            *b = array[i];
            b++;
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (A[j - 1] > left[j] && left[j] != '\0')
                swap(left[j - 1], left[j]);
        }
    }

    return 0;
}
