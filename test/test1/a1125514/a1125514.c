#include<stdio.h>
int main()
{
    int people,day;
    scanf("%d%d",&people,&day);

    while(day>0)
    {
        day=day-people;
        people++;
    }
    people--;
    printf("%d",people);

}
