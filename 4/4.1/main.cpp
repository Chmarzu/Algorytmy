#include <iostream>
using namespace std;

int main() {
    int check, n, sum = 1;

    for (check = 2; check <= 30; check++) {
        for (n = 2; n < check; n++) {
            if (check % n == 0)
                sum += n;
        }
        if (check == sum)
            cout << check << " ";
        sum = 1;
    }
    return 0;
}