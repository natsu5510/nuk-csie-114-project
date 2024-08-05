#include <stdio.h>

int main(){
    int S,D;
    while(scanf("%d%d", &S, &D)){
        int past = 0;
        while(past < D){
            past += S;
            S++;
        }
        printf("%d\n", S-1);
    }
}