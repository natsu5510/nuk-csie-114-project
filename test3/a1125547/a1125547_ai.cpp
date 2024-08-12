#include <stdio.h>
#pragma warning(disable:4996);

long long hotel_guests(int s, long long d) {
	int current_group = s;
	long long day_count = 1;

	while (day_count < d) {
		current_group++;
		day_count += current_group;
	}

	return current_group;
}

int main() {
	int s;
	long long d;

	while (scanf("%d %lld", &s, &d) == 2) {
		long long result = hotel_guests(s, d);
		printf("%lld\n", result);
	}

	return 0;
}

