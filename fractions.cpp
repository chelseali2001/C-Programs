#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Checks if the input is an int
bool is_int(string num) {
    for (int x = 0; x < num.length(); x++) {
        if (num[x] < '0' || num[x] > '9')
            return false;
    }

    return true;
}

//Converts the string to an int
int get_int(string num) {
    int new_num = 0;

    for (int x = 0; x < num.length(); x++)
        new_num += (num[x] - 48) * pow(10, num.length() - x - 1);

    return new_num;
}

//Checks if the denominator equals zero
int denom_0(string num) {
    if (get_int(num) == 0
        return true;

    return false;
}

//Checks if the numerator is a multiple of the denominator and it simplifies both numbers
bool to_lowest_terms(int& numerator, int& denominator) {
    int gcd = 0;

    if (numerator % denominator == 0) {
        return true;
    } else {
        for(int x = 1; x <= numerator && x <= denominator; x++) {
            if(numerator % x == 0 && denominator % x ==0)
                gcd = x;
        }

        numerator /= gcd;
        denominator /= gcd;

        return false;
    }
}

int main() {
    bool valid = false;
    int finish = 1, new_numer = 0, new_denom = 0;
    string numerator = "", denominator = "";

    while (finish == 1) {
        //Entering the numerator
        while (!valid) {
            cout << "Enter your numerator: ";
            cin >> numerator;

            if (is_int(numerator)) {
                valid = true;
            } else {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input, enter whole numbers only!" <<endl;
            }
        }

        //Entering the denominator
        while (valid) {
            cout << "Enter your denominator: ";
            cin >> denominator;

            if (is_int(denominator)) {
                if (!denom_0(denominator)) {
                    valid = false;
                } else {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Invalid input, denominator cannon be 0!" <<endl;
                }
            } else {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input, enter whole numbers only!" <<endl;
            }
        }

        new_numer = get_int(numerator);
        new_denom = get_int(denominator);

        cout << "The lowest terms of your fraction: ";
        
        if (to_lowest_terms(new_numer, new_denom))
            cout << new_numer / new_denom <<endl;
        else
            cout << new_numer << "/" << new_denom <<endl;

        cout << "Do you want to do another conversion? (0-no, 1-yes): ";
        cin >> finish;
    }

    return 0;
}
