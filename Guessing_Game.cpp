#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

void playGame(int range) {
    
    srand(time(0));
    int secretNumber = rand() % range + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I've picked a number between 1 and " << range << ". Can you guess it?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number." << endl;
            cout << "It took you " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);
}

int main() {
    int choice;
    bool playAgain = true;

    while (playAgain) {
        cout << "Choose difficulty level: " << endl;
        cout << "1. Easy (1-10)" << endl;
        cout << "2. Medium (1-50)" << endl;
        cout << "3. Hard (1-100)" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                playGame(10);
                break;
            case 2:
                playGame(50);
                break;
            case 3:
                playGame(100);
                break;
            default:
                cout << "Invalid choice! Defaulting to Easy level." << endl;
                playGame(10);
        }

        char response;
        cout << "Do you want to play again? (y/n): ";
        cin >> response;
        if (response == 'n' || response == 'N') {
            playAgain = false;
            cout << "Thanks for playing!" << endl;
        }
    }

    return 0;
}