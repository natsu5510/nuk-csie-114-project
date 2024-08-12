#include "stdio.h"

int main () {
    int init, dDay, day = 1;
    
    scanf("%d %d", &init, &dDay);

    while (day + init <= dDay) {
        day += init;
        init++;
    }
    
    printf("%d", init);

    return 0;
}