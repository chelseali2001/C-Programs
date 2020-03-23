#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Indicates if the provided number is in the specified range
bool check_range(int lower_bound, int upper_bound, int test_value) {
    if (test_value >= lower_bound && test_value <= upper_bound) {
        return true;
    }

    return false;
}

//Indicates if a given character is a capital letter
bool is_capital(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        return true;
    }

    return false;
}

//Indicates if a given number is even
bool is_even(int num) {
    if (num % 2 == 0) {
        return true;
    }

    return false;
}

//Indicates if a given number is odd
bool is_odd(int num) {
    if (num % 2 != 0) {
        return true;
    }

    return false;
}

//Test num1 agains num2 and returns -1 if num1 < num2, returns 0 if num1 == num2, returns 1 if num1 > num2
int equality_test(int num1, int num2) {
    if (num1 < num2) {
        return -1;
    } else if (num1 == num2) {
        return 0;
    } else if (num1 > num2) {
        return 1;
    }
}

//Tests if num1 and num2 are equal to each other within a certain precision
bool float_is_equal(float num1, float num2, float precision) {
    if (precision > abs(num1 - num2)) {
        return true;
    }

    return false;
}

//Indicates if a given string is an integer
bool is_int(string num) {
    for (int x = 0; x < num.length(); x++) {
        if (num[x] < '0' || num[x] > '9') {
            return false;
        }
    }

    return true;
}

//Indicates if the provided string contains numbers
bool numbers_present(string sentence) {
    for (int x = 0; x < sentence.length(); x++) {
        if (sentence[x] >= '0' && sentence[x] <= '9') {
            return true;
        }
    }

    return false;
}

//Indicates if the provided string contains letters
bool letters_present(string sentence) {
    for (int x = 0; x < sentence.length(); x++) {
        if ((sentence[x] >= 'A' && sentence[x] <= 'Z') || (sentence[x] >= 'a' && sentence[x] <= 'z')) {
            return true;
        }
    }

    return false;
}

//Indicates if substring exists in sentence
bool contains_sub_string(string sentence, string sub_string) {
    for (int x = 0; x < sentence.length(); x++) {
        string word = "";

        if (x < sentence.length() - sub_string.length()) {
            for (int i = x; i < x + sub_string.length(); i++) {
                word += sentence[i];
            }
        } else {
            break;
        }

        if (word == sub_string) {
            return true;
        }
    }

    return false;
}

//Provides the number of words in a given string
int word_count(string sentence) {
    int words = 1;

    for (int x = 0; x < sentence.length(); x++) {
        if (sentence[x] == ' ') {
            words++;
        }
    }

    return words;
}

//Capitalizes all letters in a given string
string to_upper(string sentence) {
    for (int x = 0; x < sentence.length(); x++) {
        if (sentence[x] >= 'a' && sentence[x] <= 'z') {
            sentence[x] = (char) (sentence[x] - 32);
        }
    }

    return sentence;
}

//Makes all letters lowercase in a given string and leave all non-letter characters unchanged
string to_lower(string sentence) {
    for (int x = 0; x < sentence.length(); x++) {
        if (sentence[x] >= 'A' && sentence[x] <= 'Z') {
            sentence[x] = (char) (sentence[x] + 32);
        }
    }

    return sentence;
}

//Takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer
int get_int(string prompt) {
    int val = 0;

    for (int x = 0; x < prompt.length(); x++) {
        if (prompt[x] < '0' || prompt[x] > '9') {
            return 0;
        }
    }

    for (int x = 0; x < prompt.length(); x++) {
        val += (prompt[x] - 48) * pow(10, prompt.length() - x - 1);
    }

    return val;
}

int main() {
    string prompt;

    cout << "Enter a string: ";
    cin >> prompt;

    //check_range()
    cout << "\nTesting check_range(1, 10, 5)" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << check_range(1, 10, 5) <<endl;
    (check_range(1, 10, 5) == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing check_range(1, 10, 11)" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << check_range(1, 10, 11) <<endl;
    (check_range(1, 10, 11) == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl; 
    
    //is_capital()
    cout << "Testing is_capital('A')" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << is_capital('A') <<endl;
    (is_capital('A') == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing is_capital('a')" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << is_capital('a') <<endl;
    (is_capital('a') == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl; 

    //is_even()
    cout << "Testing is_even(2)" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << is_even(2) <<endl;
    (is_even(2) == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing is_even(3)" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << is_even(3) <<endl;
    (is_even(3) == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl; 

    //is_odd()
    cout << "Testing is_odd(3)" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << is_odd(3) <<endl;
    (is_odd(3) == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing is_odd(2)" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << is_odd(2) <<endl;
    (is_odd(2) == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    //equality_test
    cout << "Testing equality_test(1, 2)" <<endl;
    cout << "Expected: -1" <<endl;
    cout << "Actual: " << equality_test(1, 2) <<endl;
    (equality_test(1, 2) == -1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing equality_test(1, 1)" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << equality_test(1, 1) <<endl;
    (equality_test(1, 1) == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing equality_test(2, 1)" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << equality_test(2, 1) <<endl;
    (equality_test(2, 1) == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    //float_is_equal
    cout << "Testing float_is_equal(0.123456, 0.123457, 0.00001)" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << float_is_equal(0.123456, 0.123457, 0.00001) <<endl;
    (float_is_equal(0.123456, 0.123457, 0.00001) == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing float_is_equal(0.1234, 0.2345, 0.0001)" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << float_is_equal(0.1234, 0.2345, 0.0001) <<endl;
    (float_is_equal(0.1234, 0.2345, 0.0001) == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;
    
    //is_int
    cout << "Testing is_int(\"123\")" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << is_int("123") <<endl;
    (is_int("123") == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing is_int(\"asd\")" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << is_int("asd") <<endl;
    (is_int("asd")  == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    //numbers_present
    cout << "Testing numbers_present(\"a1b\")" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << numbers_present("a1b") <<endl;
    (numbers_present("a1b") == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing numbers_present(\"asd\")" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << numbers_present("asd") <<endl;
    (numbers_present("asd")  == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;
    
    //letters_present
    cout << "Testing letters_present(\"1a2\")" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << letters_present("1a2") <<endl;
    (letters_present("1a2") == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing letters_present(\"123\")" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << letters_present("123") <<endl;
    (letters_present("123")  == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;
    
    //contains_sub_string
    cout << "Testing contains_sub_string(\"Chelsea Li\", \"sea\")" <<endl;
    cout << "Expected: 1" <<endl;
    cout << "Actual: " << contains_sub_string("Chelsea Li", "sea") <<endl;
    (contains_sub_string("Chelsea Li", "sea") == 1) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    cout << "Testing contains_sub_string(\"Chelsea Li\", \"hi\")" <<endl;
    cout << "Expected: 0" <<endl;
    cout << "Actual: " << contains_sub_string("Chelsea Li", "hi") <<endl;
    (contains_sub_string("Chelsea Li", "hi")  == 0) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;
    
    //word_count
    cout << "Testing word_count(\"Chelsea Li\")" <<endl;
    cout << "Expected: 2" <<endl;
    cout << "Actual: " << word_count("Chelsea Li") <<endl;
    (word_count("Chelsea Li") == 2) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    //to_upper
    cout << "Testing to_upper(\"Chelsea Li\")" <<endl;
    cout << "Expected: CHELSEA LI" <<endl;
    cout << "Actual: " << to_upper("Chelsea Li") <<endl;
    (to_upper("Chelsea Li") == "CHELSEA LI") ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    //to_lower
    cout << "Testing to_lower(\"Chelsea Li\")" <<endl;
    cout << "Expected: chelsea li" <<endl;
    cout << "Actual: " << to_lower("Chelsea Li") <<endl;
    (to_lower("Chelsea Li") == "chelsea li") ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    //get_int
    cout << "Testing get_int(prompt)" <<endl;
    cout << "Expected: 123" <<endl;
    cout << "Actual: " << get_int(prompt) <<endl;
    (get_int(prompt) == 123) ? cout << "PASSED\n" <<endl : cout << "FAILED\n" <<endl;

    return 0;
}