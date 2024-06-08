#include<iostream>
#include<cstdlib>
#include<ctime>
#include<thread> // For sleep_for
#include<chrono> // For chrono::milliseconds
using namespace std;

void clearScreen() {
    // ANSI escape code to clear the screen
    cout << "\033[2J\033[1;1H";
}

void loadingAnimation() {
    string loading = "Loading";
    for (int i = 0; i < 3; ++i) {
        cout << loading << std::flush;
        for (int j = 0; j < 3; ++j) {
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "." << std::flush;
        }
        clearScreen();
    }
}

void congratulationsAnimation() {
    string message = "Congratulations! You guessed the number!";
    for (char& c : message) {
        cout << c << std::flush;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << endl;
}

int main() {
    while (true) {
        clearScreen();
        loadingAnimation();

        cout << "\n\t\t************************************" << endl;
        cout << "\t\t*                                  *" << endl;
        cout << "\t\t*     Welcome to Number Guessing   *" << endl;
        cout << "\t\t*               Game!              *" << endl;
        cout << "\t\t*                                  *" << endl;
        cout << "\t\t************************************" << endl;

        cout << "\nPlease guess a number between 1 and 100. The number of attempts allowed will depend on the difficulty level you select. Best of luck!" << endl;

        cout << "\n\t\t     * * * * * * * * * * * * * * * *" << endl;
        cout << "\t\t     *                           *" << endl;
        cout << "\t\t     *   Select Difficulty:      *" << endl;
        cout << "\t\t     *   1 - Easy                *" << endl;
        cout << "\t\t     *   2 - Medium              *" << endl;
        cout << "\t\t     *   3 - Difficult           *" << endl;
        cout << "\t\t     *   0 - End the Game        *" << endl;
        cout << "\t\t     *                           *" << endl;
        cout << "\t\t     * * * * * * * * * * * * * * * *" << endl;

        int difficultyChoice;
        cout << "\nEnter the number: ";
        cin >> difficultyChoice;

        if (difficultyChoice == 0) {
            cout << "\n\t\t************************************" << endl;
            cout << "\t\t*                                  *" << endl;
            cout << "\t\t*       Game Ended. Thank you      *" << endl;
            cout << "\t\t*          for playing!            *" << endl;
            cout << "\t\t*                                  *" << endl;
            cout << "\t\t************************************" << endl;
            break;
        }

        srand(time(0));
        int specialNumber = 1 + (rand() % 100);
        int playerChoice;
        int attempts = 0;
        int maxAttempts = 0;

        switch (difficultyChoice) {
            case 1:
                maxAttempts = 10;
                cout << "\nYou have 10 attempts to find the special number between 1 and 100.";
                break;
            case 2:
                maxAttempts = 7;
                cout << "\nYou have 7 attempts to find the special number between 1 and 100.";
                break;
            case 3:
                maxAttempts = 5;
                cout << "\nYou have 5 attempts to find the special number between 1 and 100.";
                break;
            default:
                cout << "\nInvalid choice. Please enter a valid option (0, 1, 2, 3)." << endl;
                continue;
        }

        for (attempts = 1; attempts <= maxAttempts; ++attempts) {
            cout << "\n\nEnter your guess: ";
            cin >> playerChoice;

            if (playerChoice == specialNumber) {
                clearScreen();
                congratulationsAnimation();
                cout << "\t\t\tThanks for playing...." << endl;
                cout << "Play the game again with us!!\n\n" << endl;
                break;
            } else {
                cout << "Nope, " << playerChoice << " is not the right number.";
                if (playerChoice > specialNumber) {
                    cout << " The special number is smaller than the number you have chosen." << endl;
                } else {
                    cout << " The special number is greater than the number you have chosen." << endl;
                }
                cout << (maxAttempts - attempts) << " attempts left." << endl;

                if (attempts == maxAttempts) {
                    cout << "You couldn't find the special number. It was " << specialNumber << ". You lose!!\n\n";
                    cout << "Play the game again to win!!!\n\n";
                }
            }
        }
    }
    return 0;
}
