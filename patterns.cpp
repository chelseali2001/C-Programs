#include <iostream>
#include <cmath>

using namespace std;

//Asterisk pattern
void asterisk_pattern(int rows) {
    int space = rows / 2;

    for (int x = 1; x <= rows; x += 2) {
        for (int i = 0; i < space; i++)
            cout << " ";

        for (int i = 1; i <= x; i++)
            cout << "*";

        cout <<endl;
        space--;
    }

    space = 1;

    for (int x = rows - 2; x > 0; x -= 2) {
        for (int i = 0; i < space; i++)
            cout << " ";

        for (int i = 1; i <= x; i++)
            cout << "*";

        cout <<endl;
        space++;
    }
}

//Number pattern
void number_pattern() {
    int space = 4;

    for (int x = 1; x <= 9; x += 2) {
        for (int i = 0; i < space; i++)
            cout << " ";

        for (int i = 1; i <= x; i++)
            cout << i;

        cout <<endl;
        space--;
    }

    space = 1;

    for (int x = 7; x > 0; x -= 2) {
        for (int i = 0; i < space; i++)
            cout << " ";

        for (int i = 1; i <= x; i++)
            cout << i;

        cout <<endl;
        space++;
    }
}

int main() {
    int done = 0, choice = 0, rows = 0;;

    while (done == 0) {
        cout << "\nEnter 0 to print an asterisk pattern or 1 to print a number pattern: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\nHow many rows do you want: ";
            cin >> rows;
            asterisk_pattern(rows);
        } else if (choice == 1) {
            number_pattern();
        }

        cout << "Enter 0 to print another pattern or 1 to exit: ";
        cin >> done;
    }

    return 0;
}