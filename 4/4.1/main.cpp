#include <iostream>
using namespace std;

int main() {
    int sum = 1, check, n;

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