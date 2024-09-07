#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int guess;
    int maxattempts = 10;
    int rando;

    rando = (rand() % 100) + 1;

    cout << "Greetings guest! Guess a number from 1-100 for a prize!" << endl;

    for(int attempts = 1; attempts <= maxattempts; attempts++) {
        cout << "Attempt " << attempts << " of " << maxattempts << ": ";
        cin >> guess;

        if (guess == rando) {
            cout << "Great job! Come claim your prize!" << endl;
            break;
        }
        else if (abs(guess - rando) > 20) {
            cout << "Ooooh you are FREEZING!" << endl;
        }
        else if (abs(guess - rando) > 10) {
            cout << "Hmmm... getting cold there..." << endl;
        }
        else if (abs(guess - rando) > 5) {
            cout << "You're getting warmer!" << endl;
        }
        else {
            cout << "Ooooh you are so so warm. ALMOST THERE!" << endl;
        }

        if (attempts == maxattempts) {
            cout << "Uh oh! You fumbled! Well the correct number actually was " << rando << "." << endl;
        }
    }

    return 0;
}
