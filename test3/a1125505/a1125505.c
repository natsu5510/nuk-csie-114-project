#include <stdio.h>

int main(){
    int S, D, i;
    while (scanf("%d %d", &S, &D) == 2){
        for (i = S; i <= D; i++){
            D = D - S;
            S++;
            if (D == 0){
                S--;
            }
        }
        printf ("%d\n", S);
    }
    
    return 0;
}