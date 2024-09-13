using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
int x = rand()% 100 + 1;
int y = rand() % 100 + 1;
int square_sum = (x * x) + (y * y);

cout << "The sum of the squares is " << square_sum;

};