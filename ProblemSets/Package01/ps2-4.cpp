#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 6 , 8 , 10 , 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxVal = arr[0];
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    for (int i = 0; i < size; ++i) {
        if (arr[i] != maxVal) {
            sum += arr[i];
        }
    }

    cout << "The sum, not including the highest value is " << sum << endl;

    return 0;
}
