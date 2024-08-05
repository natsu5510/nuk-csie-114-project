#include <stdio.h>

int main()
{
    int D, S, P;
    printf("第一組旅行團人數:");
    scanf_s("%d", &S);
    printf("在第D天入住的旅行團人: ");
    scanf_s("%d", &D);
    while (D > 0)
        D = D - S;
    {
        S = S + 1;
        D = D - S;
    }
    printf("在第D天入住的旅行團人: %d ", S);

    return 0;
}
