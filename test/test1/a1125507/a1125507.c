 #include<stdio.h>

   int main() {
	int S,D;
	while(scanf("%d %d", &S, &D) !=EOF) {
		int day=1;
		int currentgroup=S;
		
 		while(D > day) {
		day+=currentgroup;
		currentgroup++;
		}

		printf("%d\n",currentgroup-1);
		return 0;
		}
		}






