#include <stdio.h>

int main()
{
    int S, D;
    while(scanf( "%d %d", &S, &D ) == 2){
        int past = 0;
        while( past < D ){
            past += S;
            S++;
        }
        printf( "%d", S-1 );
    }

    return 0;
}
