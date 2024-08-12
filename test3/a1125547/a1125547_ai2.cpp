#include <stdio.h>
#pragma warning(disable:4996);

int find_group_size(int S, long long D) {
	long long current_day = 1;
	int current_group_size = S;

	while (current_day + current_group_size <= D) {
		current_day += current_group_size + 1;  // next group arrives the day after the previous group leaves
		current_group_size += 1;
	}

	return current_group_size;
}

int main() {
	int S; // Initial group size
	long long D; // Day to find the group size for

	while (scanf("%d %lld", &S, &D) != EOF) {
		printf("%d\n", find_group_size(S, D));
	}

	return 0;
}
