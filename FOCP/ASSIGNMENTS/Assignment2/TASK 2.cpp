#include <iostream>
#include <cmath>
using namespace std;

// Function for addition
double addition(double a, double b) {
    return a + b;
}

// Function for subtraction
double subtraction(double a, double b) {
    return a - b;
}

// Function for multiplication
double multiplication(double a, double b) {
    return a * b;
}

// Function for division with error handling for division by zero
double division(double a, double b) {
    if (b == 0) {
        cout << "ERROR:: Division by 0 is Undefined\n";
        return 0;
    }
    return a / b;
}

// Function to calculate the remainder (modulus)
double Remainder(double a, double b) {
    return fmod(a, b);
}

// Function to calculate exponentiation (a^b)
double Exponentiation(double a, double b) {
    return pow(a, b);
}

int main() {
    // Initialize both numbers to zero
    double num1 = 0, num2 = 0;
    char choice;

    while (true) {
        // Display the current numbers
        cout << "First Number = " << num1 << " | Second Number = " << num2 << endl;
        cout << "n - Enter New Numbers\n\n";

        // Prompt for new numbers if both are zero
        if (num1 == 0 && num2 == 0) {
            cout << "Enter First Number: ";
            cin >> num1;
            cout << "Enter Second Number: ";
            cin >> num2;
        }

        // Display calculator menu options
        cout << "\nCalculator Menu\n";
        cout << "a. Addition\n";
        cout << "b. Subtraction\n";
        cout << "c. Multiplication\n";
        cout << "d. Division\n";
        cout << "e. Remainder\n";
        cout << "f. Exponentiation\n";
        cout << "x. Exit The Program\n";
        cout << "Select an Option: ";
        cin >> choice;

        // Option to exit the program
        if (choice == 'x') {
            cout << "Exiting the Program.\n";
            break;
        }

        // Option to enter new numbers
        if (choice == 'n') {
            cout << "Enter First Number: ";
            cin >> num1;
            cout << "Enter Second Number: ";
            cin >> num2;
            continue; // Restart the loop with the new numbers
        }

        // Perform operation based on user's choice
        switch (choice) {
            case 'a':
                // Addition operation
                cout << "Sum of " << num1 << " and " << num2 << " is " << addition(num1, num2) << endl;
                break;
            case 'b':
                // Subtraction operation
                cout << "Difference of " << num2 << " from " << num1 << " is " << subtraction(num1, num2) << endl;
                break;
            case 'c':
                // Multiplication operation
                cout << "Multiplication of " << num1 << " and " << num2 << " is " << multiplication(num1, num2) << endl;
                break;
            case 'd':
                // Division operation
                cout << "Division of " << num1 << " by " << num2 << " is " << division(num1, num2) << endl;
                break;
            case 'e':
                // Remainder operation
                cout << "Remainder of " << num1 << " divided by " << num2 << " is " << Remainder(num1, num2) << endl;
                break;
            case 'f':
                // Exponentiation operation
                cout << num1 << " raised to the power of " << num2 << " is " << Exponentiation(num1, num2) << endl;
                break;
            default:
                // Handling invalid choices
                cout << "Invalid Choice. Please TRY AGAIN!!!\n";
        }
    }

    return 0;
}
