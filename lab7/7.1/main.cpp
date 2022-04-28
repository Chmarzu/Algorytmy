#include<iostream>
#include <windows.h>

using namespace std;

void NumbChar(int size);
void ch_merge_sort(char *array, int start, int end);
void ch_merge(char *array, int start, int middle, int end);
void NegNumbFloat(int size);
void f_merge_sort(float *array, int start, int end);
void f_merge(float *array, int start, int middle, int end);

int main() {
    int size, mode = 0;

    do {        //Pobranie rozmiaru tablicy sortowania
        cout << "Podaj ilosc znakow do posortowania:" << endl;
        cin >> size;

        if (size < 2)
            cout << endl << "Blad!" << endl;
        cout << endl;
    } while (size < 2);

    do {        //Wybor typu sortowanych znakow
        cout << "Wypierz opcje:" << endl;
        cout << "(1) Sortowanie liczb naturalnych (dotatnie, calkowite) lub znakow" << endl;
        cout << "(2) Sortowanie liczb ujemnych lub zmiennoprzecinkowych" << endl;
        cin >> mode;

        if (mode == 1)
            NumbChar(size);
        else if (mode == 2)
            NegNumbFloat(size);
        else
            cout << endl << "Blad!";
        cout << endl;
    } while (mode != 1 && mode != 2);

    cout << endl;
    fflush(stdin);
    getchar();
    return 0;
}

void NumbChar(int size) {
    int i;
    char array[size];

    for (i = 0; i < size; i++) {        //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> array[i];
    }

    ch_merge_sort(&array[0], 0, size - 1);

    cout << endl << "Posortowana tablica:" << endl;     //Wynik
    for (i = 0; i < size; i++)
        cout << array[i] << ' ';
}

void ch_merge_sort(char *array, int start, int end) {
    int middle;

    if (start != end) {     //Podzial na pomniejsze zbiory
        middle = (start + end) / 2;
        ch_merge_sort(array, start, middle);
        ch_merge_sort(array, middle + 1, end);
        ch_merge(array, start, middle, end);
    }
}

void ch_merge(char *array, int start, int middle, int end) {
    char temp_array[end - start];
    int i = start, j = middle + 1, k = 0;

    while (i <= middle && j <= end) {       //Sortowanie
        if (*(array + j) < *(array + i)) {
            temp_array[k] = *(array + j);
            j++;
        } else {
            temp_array[k] = *(array + i);
            i++;
        }
        k++;
    }

    //Wypelnianie pomocniczej tablicy brakujaca zawartoscia
    if (i <= middle) {
        while (i <= middle) {
            temp_array[k] = *(array + i);
            i++;
            k++;
        }
    } else {
        while (j <= end) {
            temp_array[k] = *(array + j);
            j++;
            k++;
        }
    }

    for (i = 0; i <= end - start; i++)      //Przeniesienie wyniku sortowania do glownej tablicy
        *(array + (start + i)) = temp_array[i];

    cout << endl;
    for (i = start; i <= end; i++)      //Wyswietlenie wyniku sortowania mniejszego zbioru
        cout << *(array + i) << " ";
    Sleep(2000);
    cout << endl;
}

void NegNumbFloat(int size) {
    int i;
    float array[size];

    for (i = 0; i < size; i++) {        //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> array[i];
    }

    f_merge_sort(&array[0], 0, size - 1);

    cout << endl << "Posortowana tablica:" << endl;     //Wynik
    for (i = 0; i < size; i++)
        cout << array[i] << ' ';
}

void f_merge_sort(float *array, int start, int end) {
    int middle;

    if (start != end) {     //Podzial na pomniejsze zbiory
        middle = (start + end) / 2;
        f_merge_sort(array, start, middle);
        f_merge_sort(array, middle + 1, end);
        f_merge(array, start, middle, end);
    }
}

void f_merge(float *array, int start, int middle, int end) {
    float temp_array[end - start];
    int i = start, j = middle + 1, k = 0;

    while (i <= middle && j <= end) {       //Sortowanie
        if (*(array + j) < *(array + i)) {
            temp_array[k] = *(array + j);
            j++;
        } else {
            temp_array[k] = *(array + i);
            i++;
        }
        k++;
    }

    //Wypelnianie pomocniczej tablicy brakujaca zawartoscia
    if (i <= middle) {
        while (i <= middle) {
            temp_array[k] = *(array + i);
            i++;
            k++;
        }
    } else {
        while (j <= end) {
            temp_array[k] = *(array + j);
            j++;
            k++;
        }
    }

    for (i = 0; i <= end - start; i++)      //Przeniesienie wyniku sortowania do glownej tablicy
        *(array + (start + i)) = temp_array[i];

    cout << endl;
    for (i = start; i <= end; i++)      //Wyswietlenie wyniku sortowania mniejszego zbioru
        cout << *(array + i) << " ";
    Sleep(2000);
    cout << endl;
}