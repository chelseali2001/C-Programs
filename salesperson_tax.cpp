#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    char state = 'A';
    int monthly_salary = 0, months = 0, cost = 0, cars = 0, misconducts = 0, year = 0;
    int avg_price = 0, annual_salary = 0, profit = 0, deduction = 0, gross_income = 0, tax = 0;  

    srand(time(NULL));

    cout << "Enter your monthly salary: ";
    cin >> monthly_salary;

    cout << "Enter number of months you worked in the past year: ";
    cin >> months;

    cout << "Enter the cost of the car: ";
    cin >> cost;

    cout << "Enter number of cars you've sold in the past year: ";
    cin >> cars;

    cout << "Enter number of misconducts observed in the past year: ";
    cin >> misconducts;

    cout << "Which tax year are you in, enter 1 for 2017, 2 for 2018: ";
    cin >> year;

    cout << "Which state are you in, enter A, B, or C: ";
    cin >> state;

    avg_price = rand() % (int) round(cost * 0.06) + round(cost * 1.05);
    annual_salary = monthly_salary * months;
    profit = cars * (avg_price - cost);
    
    if (misconducts != 0) {
        deduction = 100 * pow(2, misconducts - 1);
    }

    gross_income = annual_salary + round(0.02 * profit) - deduction;

    cout << "\nThe average selling price, generated randomly, is $" << avg_price << ", you will earn 2% of the profit, which is $" << (int) round(0.02 * profit) << "." <<endl;

    cout << "\nThe gross income is: $" << gross_income <<endl;
    cout << "The tax you need to pay is: $";

    switch (year) {
        case 1:
            switch (state) {
                case 'A':
                    tax = round(0.06 * gross_income);
                    break;
                case 'B':
                    if (gross_income > 2000 && gross_income <= 10000) {
                        tax = 100;
                    } else if (gross_income > 10000) {
                        tax = round((gross_income - 10000) * 0.1) + 100;
                    }

                    break;
                case 'C':
                    if (gross_income <= 3500) {
                        tax = round(gross_income * 0.05);
                    } else if (gross_income > 3500 && gross_income <= 9000) {
                        tax = round((gross_income - 3500) * 0.07) + 175;
                    } else if (gross_income > 9000 && gross_income <= 125000) {
                        tax = round((gross_income - 9000) * 0.09) + 560;
                    } else if (gross_income > 125000) {
                        tax = round((gross_income - 125000) * 0.099) + 11000;
                    }
                    
                    break;
            }

            break;
        case 2:
            switch (state) {
                case 'A':
                    tax = round(gross_income * 0.08);
                    break;
                case 'B':
                    if (gross_income > 2500 && gross_income <= 10000) {
                        tax = 115;
                    } else if (gross_income > 10000) {
                        tax = round((gross_income - 10000) * 0.105) + 115;
                    }

                    break;
                case 'C':
                    if (gross_income <= 3450) {
                        tax = round(gross_income * 0.05);
                    } else if (gross_income > 3450 && gross_income <= 8700) {
                        tax = round((gross_income - 3450) * 0.07) + 172.5;
                    } else if (gross_income > 8700 && gross_income <= 125000) {
                        tax = round((gross_income - 8700) * 0.09) + 540;
                    } else if (gross_income > 125000) {
                        tax = round((gross_income - 125000) * 0.099) + 11007; 
                    }
                    
                    break;
            }

            break;
    }

    cout << tax <<endl;
    cout << "Remaining: $" << gross_income - tax <<endl;

    return 0;
}