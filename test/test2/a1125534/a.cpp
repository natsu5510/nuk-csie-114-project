#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	 
	int n;
	int ugly_number = 0;
	scanf("%d", &n);

	for(int i = 1;i<= 2023;i++){
		
		if (i == 1 || i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
			ugly_number++;
		}

		
	}

	if (n == ugly_number) {
		printf("%d", i);
	}
	
}