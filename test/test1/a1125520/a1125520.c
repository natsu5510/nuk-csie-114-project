#include <stdio.h>

int main()
{
    int S, D;
    scanf( "%d %d", &S, &D );

    int past = 0;
    while( past < D ){
        past += S;
        S++;
    }
    printf( "%d", S-1 );

    return 0;
}
