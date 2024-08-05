// Online C compiler to run C program online
#include <stdio.h>

int main() {

	int num, c = 0, ans = 0;
	scanf("%d", &num);
	while (c<num){
		ans = ans + 1;
		if (ans == 1 || ans % 2 == 0 || ans % 3 == 0 || ans % 5 == 0 && ans % 7 == 0){
			c = c + 1;
		}
		else{
			c = c;
		}
	}
	printf("%d", ans);

	return 0;
}