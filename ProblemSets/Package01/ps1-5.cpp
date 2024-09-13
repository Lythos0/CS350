using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
int x = rand()% 201 - 100;
if (x < 0){
    cout << x << " Is Negative";
}

else if(x > 0){
    cout << x << " Is Positive";
}

else if(x ==0){
    cout << x << " Is Zero";
}


};