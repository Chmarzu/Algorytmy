#include <iostream>
#include <windows.h>

using namespace std;

void Sort(int size);
void ch_merge_sort(char *array, int start, int end);
void ch_merge(char *array, int start, int middle, int end);

int main() {
    int size = 0;

    do {        //Pobranie rozmiaru tablicy sortowania
        cout << "Podaj ilosc znakow do posortowania:" << endl;
        cin >> size;

        if (size < 2)
            cout << endl << "Blad!" << endl;
        cout << endl;
    } while (size < 2);

    Sort(size);

    cout << endl;
    fflush(stdin);
    getchar();
    return 0;
}

void Sort(int size) {
    int i, j, min;
    unsigned short mode;
    clock_t diff[3] = {0, 0, 0};
    char tab[size];
    char tab2[size], *ptab, pivot, left[size], *pleft, right[size], *pright;

    for (i = 0; i < size; i++) {        //Pobranie elementow do sortowania
        cout << "Podaj element numer " << i + 1 << ":" << endl;
        cin >> tab[i];
    }

    do {
        cout << "Wybierz algorytm sortujacy:" << endl;
        for (i = 1; i < 6; i++) {
            switch (i) {
                case 1:
                    cout << "(" << i << ") Exchange Sort";
                    break;
                case 2:
                    cout << "(" << i << ") Insertion Sort";
                    break;
                case 3:
                    cout << "(" << i << ") Selection Sort";
                    break;
                case 4:
                    cout << "(" << i << ") Quick Sort";
                    break;
                case 5:
                    cout << "(" << i << ") Merge Sort";
                    break;
                default:
                    cout << endl << "Blad!" << endl;
                    break;
            }
            cout << endl;
        }
        cin >> mode;
        cout << endl;
    } while (mode < 1 || mode > 5);

    switch (mode) {
        case 1:
            diff[0] = clock();

            for (i = 0; i < size; i++) {
                for (j = 1; j < size; j++) {
                    if (tab[j - 1] > tab[j])
                        swap(tab[j - 1], tab[j]);
                }
            }

            diff[1] = clock();
            diff[2] = diff[1] - diff[0];
            break;
        case 2:
            diff[0] = clock();

            tab2[0] = tab[0];
            for (i = 1; i < size; i++) {
                tab2[i] = tab[i];
                for (j = 0; j < size; j++) {
                    if (tab2[j] > tab2[i])
                        swap(tab2[j], tab2[i]);
                }
            }

            for (i = 0; i < size; i++)
                tab[i] = tab2[i];

            diff[1] = clock();
            diff[2] = diff[1] - diff[0];
            break;
        case 3:
            diff[0] = clock();

            for (i = 0; i < size - 1; i++) {        //Sortowanie
                min = i;
                for (j = i; j < size; j++) {
                    if (tab[j] < tab[min]) {
                        min = j;
                    }
                }
                swap(tab[min], tab[i]);
            }

            diff[1] = clock();
            diff[2] = diff[1] - diff[0];
            break;
        case 4:
            diff[0] = clock();

            ptab = &tab[0];
            pleft = &left[0];
            pright = &right[0];

            for (i = 0; i < size; i++) {
                tab[size] = '\0';
                left[i] = right[i] = '\0';
            }

            pivot = tab[0];     //Wybor pivota

            for (i = 1; i < size; i++) {        //Podzial na mniejsze tablice
                if (tab[i] < pivot) {
                    *pleft = tab[i];
                    pleft++;
                } else {
                    *pright = tab[i];
                    pright++;
                }
            }

            //Sortowanie mniejszych tablic
            if (left[0] != '\0') {
                for (i = 0; i < size; i++) {
                    for (j = 1; j < size; j++) {
                        if (left[j - 1] > left[j] && left[j] != '\0')
                            swap(left[j - 1], left[j]);
                    }
                }
            }

            if (right[0] != '\0') {
                for (i = 0; i < size; i++) {
                    for (j = 1; j < size; j++) {
                        if (right[j - 1] > right[j] && right[j] != '\0')
                            swap(right[j - 1], right[j]);
                    }
                }
            }

            //Przeniesienie posortowanych elementow do glownej tablicy
            pleft = &left[0];
            while (*pleft != '\0') {
                *ptab = *pleft;
                ptab++;
                pleft++;
            }

            *ptab = pivot;
            ptab++;

            pright = &right[0];
            while (*pright != '\0') {
                *ptab = *pright;
                ptab++;
                pright++;
            }

            diff[1] = clock();
            diff[2] = diff[1] - diff[0];
            break;
        case 5:
            diff[0] = clock();
            ch_merge_sort(&tab[0], 0, size - 1);
            diff[1] = clock();
            diff[2] = diff[1] - diff[0];
            break;
    }

    cout << endl << "Posortowana tablica:" << endl;     //Wynik
    for (i = 0; i < size; i++)
        cout << tab[i] << ' ';

    cout << endl << "Czas sortowania: " << diff[2];
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