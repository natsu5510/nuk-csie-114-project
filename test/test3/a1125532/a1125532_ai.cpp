#include <stdio.h>

int find_group_size(int S, int D) {
	// Initialize variables
	int group_size = S;
	int total_days = S;

	// Loop until total_days is less than D
	while (total_days < D) {
		// Increase the group size
		group_size += 1;
		// Add the group size to total_days
		total_days += group_size;
	}

	// Return the group size
	return group_size;
}

int main() {
	// Test the function
	printf("%d\n", find_group_size(4, 10));  // Output: 5

	return 0;
}