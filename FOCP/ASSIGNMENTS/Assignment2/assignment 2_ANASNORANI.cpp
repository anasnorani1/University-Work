#include <iostream> // Include iostream for input and output operations
#include <iomanip>  // Include iomanip for std::setw function
#include <cmath>// Include cmath for exponentiation
#include <ctime>
using namespace std;
// TASK 1 STARTED
// Function to generate the number pattern
void task1(int rows) {
    // Loop through each row
    for (int i = 1; i <= rows; ++i) {
        // Print spaces for alignment
        for (int space = 1; space <= rows - i; ++space) {
            cout << "   "; // Add spaces to align the numbers in a pyramid shape
        }

        // Print increasing numbers starting from the current row number
        int num = i; // Initialize num to the current row number
        for (int j = 1; j <= i; ++j) {
            cout << setw(2) << num << " "; // Print the number with a width of 2
            ++num; // Increment the number for the next position
        }

        // Print decreasing numbers
        num -= 2; // Adjust to the last printed number to start mirroring
        for (int j = 1; j < i; ++j) { // One less than 'i' for mirroring
            cout << setw(2) << num << " "; // Print the mirrored number
            --num; // Decrement the number for the next position
        }

        cout << endl; // Move to the next line after printing both sides
    }
}// Start of Task 2:
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

// Function to generate a random number between 1 and 1000
int generateTargetNumber() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    return rand() % 1000 + 1; // Generate and return a random number between 1 and 1000
}

// Function to get the player's guess
int getPlayerGuess() {
    int guess;
    cout << "\nEnter your guess: ";
    cin >> guess; // Read player's guess
    return guess; // Return the guess
}

// Function to evaluate the guess and provide feedback
string evaluateGuess(int guess, int targetNumber) {
    int difference = abs(guess - targetNumber); // Calculate the absolute difference

    // Provide feedback based on the difference
    if (difference == 0) return "Correct! You've guessed the number.\n";
    else if (difference > 200) return (guess > targetNumber) ? "Too high!\n" : "Too low!\n";
    else if (difference > 10) return (guess > targetNumber) ? "High!\n" : "Low!\n";
    else return (guess > targetNumber) ? "Slightly high!\n" : "Slightly low!\n";
}

// Function to calculate the score penalty based on the difference
int applyDynamicPenalty(int difference) {
    // Return penalty based on how far off the guess is
    if (difference > 500) return 100;
    else if (difference > 300) return 50;
    else if (difference > 200) return 30;
    else if (difference > 100) return 20;
    else if (difference > 10) return 10;
    return 0; // No penalty for differences within 10
}

// Function to calculate the additional penalty based on the number of attempts
int applyAttemptPenalty(int attempts) {
    // Apply penalties based on the range of attempts
    if (attempts >= 2 && attempts <= 5) return 10 * attempts;
    else if (attempts >= 6 && attempts <= 10) return 20 * attempts;
    else if (attempts > 10) return 50 * attempts;
    return 0; // No penalty for 1 attempt
}

// Function to calculate the bonus points based on few attempts
int applyBonusPoints(int attempts) {
    // Provide bonus points for fewer attempts
    if (attempts <= 3) return 200;
    else if (attempts <= 6) return 100;
    return 0; // No bonus for attempts more than 6
}

// Main function for the game
void playGame() {
    int targetNumber = generateTargetNumber(); // Random target number
    int guess, attempts = 0, score = 1000; // Initialize variables

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have chosen a number between 1 and 1000. Try to guess it!\n";

    // Game loop
    while (true) {
        guess = getPlayerGuess(); // Get player's guess
        attempts++; // Increment attempt count
        int difference = abs(guess - targetNumber); // Calculate difference

        cout << evaluateGuess(guess, targetNumber); // Display feedback

        if (difference == 0) break; // End loop if the guess is correct

        // Apply penalty based on difference and update score
        int penalty = applyDynamicPenalty(difference);
        score -= penalty;
        if (penalty > 0) { // Display penalty message if applied
            cout << "Dynamic Penalty: -" << penalty << " points has been Applied.\n";
        }
        cout << "Current score: " << score << endl; // Display updated score
    }

    // Apply additional penalty based on the number of attempts and update score
    int attemptPenalty = applyAttemptPenalty(attempts);
    score -= attemptPenalty;
    if (attemptPenalty > 0) { // Display attempt penalty message if applied
        cout << "Attempt-based Penalty: -" << attemptPenalty << " points for " << attempts << " attempts.\n";
    }

    // Apply bonus points for fewer attempts and update score
    int bonusPoints = applyBonusPoints(attempts);
    score += bonusPoints;
    if (bonusPoints > 0) { // Display bonus points message if applied
        cout << "Bonus Points: +" << bonusPoints << " points for " << attempts << " attempts.\n";
    }

    // Ensure score doesn't drop below zero
    if (score < 0) score = 0;

    // Display final game results
    cout << "\nGame Over! You took " << attempts << " attempts to guess the number.\n";
    cout << "Your final score is: " << score << endl;
}

void task3() {
    playGame(); // Start the game

}


int main() {
    int num1=1,num2=2,num3=3,num4=4,num5=5;
    int choice;
   while(true){
    label1:
    cout << "\nMain Menu \n";
    cout << "1. Numbers Pyramid\n";
    cout << "2. Calculator\n";
    cout << "3. Guessing Game\n";
    cout << "4. Exit Whole Program\n";
    cout<<"Select an option to evaluate task: ";
    cin >> choice;
    while(true){

    if (choice==1){     
    cout << "Task 1 Started\n";
    int rows; // Variable to hold the number of rows for the pattern

    // Prompt user for the number of rows
    cout << "Enter the number of rows: ";
    cin >> rows; // Read the number of rows from user input

    // Call the function to generate and display the pattern
    task1(rows); // Directly displays the pattern in the function
    break;
    cout <<endl;
        cout <<endl;
    }

    //  TAsk 2
    else if(choice == 2)
{
    // Initialize both numbers to zero
    double num1 = 0, num2 = 0;
    char choice;
    
        cout << "Task 2 Started\n";

    while (true) {
        // Display the current numbers
        cout << "First Number = " << num1 << " | Second Number = " << num2 << endl;
        // Display calculator menu options
        cout << "\nCalculator Menu\nSelect an Option from (a-f) , x ,n\n";
        cout << "a. Addition\n";
        cout << "b. Subtraction\n";
        cout << "c. Multiplication\n";
        cout << "d. Division\n";
        cout << "e. Remainder\n";
        cout << "f. Exponentiation\n";
        cout << "x. Exit The Program\n";
        cout << "n - Enter New Numbers\n\n";

        cout << "Select an Option: ";
        cin >> choice;

        // Prompt for new numbers if both are zero
        if (num1 == 0 && num2 == 0) {
            cout << "The BOth Numbers are zero TRY AGAIN !!!\n";
            cout << "Enter First Number: ";
            cin >> num1;
            cout << "Enter Second Number: ";
            cin >> num2;
        }

       
        // Option to exit the program
        if (choice == 'x') {
            cout << "Exiting the Program.\n\n\n";
            goto label1;
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
                cout << "Sum of " << num1 << " and " << num2 << " is " << addition(num1, num2) <<endl<<endl<< endl;
                break;
            case 'b':
                // Subtraction operation
                cout << "Difference of " << num2 << " from " << num1 << " is " << subtraction(num1, num2) <<endl<<endl<< endl;
                break;
            case 'c':
                // Multiplication operation
                cout << "Multiplication of " << num1 << " and " << num2 << " is " << multiplication(num1, num2)  << endl << endl << endl;
                break;
            case 'd':
                // Division operation
                cout << "Division of " << num1 << " by " << num2 << " is " << division(num1, num2) << endl<<endl<<endl;
                break;
            case 'e':
                // Remainder operation
                cout << "Remainder of " << num1 << " divided by " << num2 << " is " << Remainder(num1, num2) << endl<<endl<<endl;
                break;
            case 'f':
                // Exponentiation operation
                cout << num1 << " raised to the power of " << num2 << " is " << Exponentiation(num1, num2) << endl<<endl<<endl;
                break;
            default:
                // Handling invalid choices
                cout << "Invalid Choice. Please TRY AGAIN!!!\n";
        };
   continue;
    }
         

}
   else if(choice ==3){
    cout << "Task 3 Started\n";
    task3() ;

   
goto label1;
   }
   else if(choice ==4){
  cout << "THE WHOLE PROGRAM HAS ENDED";
    return 0;
  
break;
   }
   else if ( abs(choice) >4){
    cout << "InvaliD Choice ! TRY AGAIN FROM GIVEN MENU";
    goto label1;
   }
    }
    }
    return 0; // Return 0 to indicate successful completion
}
