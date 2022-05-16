#include <fstream>
#include <ctime>

using namespace std;

int main() {
    int i, roz = 10, temp;
    srand(time(NULL));

    ofstream file;
    file.open("10.txt");
    for (i = 0; i < roz; i++) {
        temp = rand() % 10;
        file << temp << "\n";
    }
    file.close();
    return 0;
}