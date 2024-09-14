#include <iostream>
using namespace std;

double thefunction(double a, double b, double c, double d) {
    return a * d * d + b * d + c;
}

int main() {
    double a, b, c, d;
  
    cout << "Enter the values for a, b, c, and d: ";
    cin >> a >> b >> c >> d;
    
    double result = thefunction(a, b, c, d);
    
    cout << "Your results are : " << result << endl;
    
    return 0;
}
