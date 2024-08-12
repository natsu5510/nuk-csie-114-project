# include <stdio.h>
# pragma warning (disable:4996)

int main() {

	int max_x, max_y;
	scanf("%d %d", &max_x, &max_y);

	int x, y;
	char direction;
	scanf("%d %d %c", &x, &y, &direction);

	int scent_x, scent_y;

	char order;
	while (scanf("%c", &order)!=EOF) {
			
		if (direction == 'N' && order == 'L')
			direction = 'W';
		else if (direction == 'N' && order == 'R')
			direction = 'E';
		else if (direction == 'E' && order == 'L')
			direction = 'N';
		else if (direction == 'E' && order == 'R')
			direction = 'S';
		else if (direction == 'S' && order == 'L')
			direction = 'E';
		else if (direction == 'S' && order == 'R')
			direction = 'W';
		else if (direction == 'W' && order == 'L')
			direction = 'S';
		else if (direction == 'W' && order == 'R')
			direction = 'N';
		else if (direction == 'N' && order == 'F')
			y += 1;
		else if (direction == 'E' && order == 'F')
			x += 1;
		else if (direction == 'S' && order == 'F')
			y -= 1;
		else if (direction == 'W' && order == 'F')
			x -= 1;
		
		if (x > max_x || y > max_y) {
			scent_x = x - 1;
		}
		else if ( y > max_y) {
			scent_y = y - 1;
		}
		
		
		
	}
	
	if (x <= max_x && y <= max_y) {
		printf("%d %d %c\n", x, y, direction);
	}
	else printf("%d %d %c LOST\n", x, y, direction);
}