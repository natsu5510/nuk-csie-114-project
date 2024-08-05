# include <stdio.h>
# pragma warning (disable:4996)

int main() {

	int s, d;
	scanf("%d %d", &s, &d);
	int i = s;

	while (i!=d) {
		s++;
		i += s ;
	}
	printf("%d", s);
}
