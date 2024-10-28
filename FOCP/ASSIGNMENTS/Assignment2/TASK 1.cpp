#include <iostream> // Include iostream for input and output operations
#include <iomanip>  // Include iomanip for std::setw function
#include <sstream>  // Include sstream for string stream
using namespace std;

// Function to generate the number pattern
string task1(int rows) {
    stringstream task1; // String stream to build the output string

    // Loop through each row
    for (int i = 1; i <= rows; ++i) {
        // Print spaces for alignment
        for (int space = 1; space <= rows - i; ++space) {
            task1 << "   "; // Add spaces to align the numbers in a pyramid shape
        }

        // Print increasing numbers starting from the current row number
        int num = i; // Initialize num to the current row number
        for (int j = 1; j <= i; ++j) {
            task1 << setw(2) << num << " "; // Add the number with a width of 2
            ++num; // Increment the number for the next position
        }

        // Print decreasing numbers
        num -= 2; // Adjust to the last printed number to start mirroring
        for (int j = 1; j < i; ++j) { // One less than 'i' for mirroring
            task1 << setw(2) << num << " "; // Add the mirrored number
            --num; // Decrement the number for the next position
        }

        task1 << endl; // Move to the next line after printing both sides
    }

    return task1.str(); // Return the final built string
}

int main() {
    int rows; // Variable to hold the number of rows for the pattern

    // Prompt user for the number of rows
    cout << "Enter the number of rows: ";
    cin >> rows; // Read the number of rows from user input

    // Call the function and print the result
    string result = task1(rows); // Generate the pattern
    cout << result; // Output the result

    return 0; // Return 0 to indicate successful completion
}
