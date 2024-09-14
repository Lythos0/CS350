#include <iostream>
using namespace std;

int main()

{
int sum = 0;

    for (int i = 100; i <= 300; ++i) {
        if (i % 5 != 0) {
            sum += i;
        }
    }
cout << "The sum of non multiples of five in this range is " << sum << endl;
    return 0;
}