#include <stdio.h>
#pragma warning(disable:4996)

// Function to find the size of the group staying in the hotel on day D
int find_group_size(int S, long long D) {
	int current_group_size = S;
	long long current_day = 1;

	while (1) {
		// Check if the current group's stay includes day D
		if (current_day + current_group_size - 1 >= D) {
			return current_group_size;
		}

		// Move to the next group
		current_day += current_group_size;
		current_group_size++;
	}
}

int main() {
	int S;
	long long D;

	// Read input until EOF (end of file)
	while (scanf("%d %lld", &S, &D) != EOF) {
		printf("%d\n", find_group_size(S, D));
	}

	return 0;
}
