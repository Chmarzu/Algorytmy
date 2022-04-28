#include<iostream>

using namespace std;

void merge_sort(int array[], int start, int end);
void merge(int array[], int start, int middle, int end);

int main() {
    int i, size;

    do {        //Pobranie rozmiaru tablicy sortowania
        cout << "Podaj ilosc znakow do posortowania:" << endl;
        cin >> size;

        if (size < 2)
            cout << endl << "Blad!" << endl;
        cout << endl;
    } while (size < 2);

    int array[size];

    for (i = 0; i < size; i++) {        //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> array[i];
    }

    merge_sort(array, 0, size - 1);

    cout << endl << "Posortowana tablica:" << endl;     //Wynik
    for (i = 0; i < size; i++)
        cout << array[i] << ' ';

    fflush(stdin);
    getchar();
    return 0;
}

void merge_sort(int array[], int start, int end) {
    int middle;

    if (start != end) {
        middle = (start + end) / 2;
        merge_sort(array, start, middle);
        merge_sort(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

void merge(int array[], int start, int middle, int end) {
    int temp_array[end - start];
    int i = start, j = middle + 1, k = 0;

    while (i <= middle && j <= end) {
        if (array[j] < array[i]) {
            temp_array[k] = array[j];
            j++;
        } else {
            temp_array[k] = array[i];
            i++;
        }
        k++;
    }

    if (i <= middle) {
        while (i <= middle) {
            temp_array[k] = array[i];
            i++;
            k++;
        }
    } else {
        while (j <= end) {
            temp_array[k] = array[j];
            j++;
            k++;
        }
    }

    for (i = 0; i <= end - start; i++)
        array[start + i] = temp_array[i];

    cout << endl;
    for (i = start; i <= end; i++)
        cout << array[i] << " ";
    cout << endl;
}