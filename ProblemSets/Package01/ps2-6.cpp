#include <iostream>
using namespace std;

void makeAsterisks(int length) {
    for (int i = 1; i <= length; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    makeAsterisks(5);
    return 0;
}
