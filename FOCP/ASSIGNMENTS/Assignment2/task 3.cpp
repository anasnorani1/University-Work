#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

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
