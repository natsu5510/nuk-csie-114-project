#include <iostream>
using namespace std;

// Function to calculate the sum of the arithmetic sequence
long long sum(long long s, long long n) {
    return (n + s) * (n - s + 1) / 2;
}

// Function to perform binary search
long long bsearch(long long s, long long d) {
    // Define the lower and upper bounds
    long long low = s, high = 1e8, mid;
    // Repeat until the bounds converge
    while (low < high) {
        // Find the middle value
        mid = low + (high - low) / 2;
        // Check if the sum is greater than or equal to the given day
        if (sum(s, mid) >= d) {
            // Update the upper bound
            high = mid;
        } else {
            // Update the lower bound
            low = mid + 1;
        }
    }
    // Return the answer
    return low;
}

int main() {
    // Declare the variables for the initial size and the given day
    long long s, d;
    // Read the input until the end of file
    while (cin >> s >> d) {
        // Print the output
        cout << bsearch(s, d) << endl;
    }
    return 0;
}
