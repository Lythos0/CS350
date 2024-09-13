using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
int x = rand()% 100 + 1;
if (x % 2 ==0){
    cout << x << " Is Even";
}
else {
    cout << x << " Is Odd";
}

};