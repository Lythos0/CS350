#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int num;
    do {
        cout << "Please enter a number ";
        cin >> num;
    } while (!isPrime(num));

    cout << num << " is a prime number" << endl;

    return 0;
}
