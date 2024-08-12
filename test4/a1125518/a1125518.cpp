#include <stdio.h>
#pragma warning(disable : 4996)

int main(){
	int d, r, w, k = 2;

	while (scanf("%d", &d) != EOF){
		k = 1;
		w = 0;
		while (w < d){
			r = k;
			while (r % 2 == 0 && r != 1){
				r = r / 2;
			}
			while (r % 3 == 0 && r != 1){
				r = r / 3;
			}
			while (r % 5 == 0 && r != 1){
				r = r / 5;
			}

			if (r == 1) {
				w++;
			}
			k++;
		}
		 printf("%d\n", k - 1);
	}
	return 0;
}