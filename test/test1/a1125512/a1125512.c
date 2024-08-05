#include <stdio.h>

int people; //people is how many member of first group.
int day;    //day is after how many days you want to check the size of the group of the members.

int main(){

    while(scanf("%d%d",&people ,&day)){

        for(int i = people ; i < day; i){

            people++;                           //next group.

            i += people;                        //count day;

        }
        
        printf("%d\n", people);

    }
    
}

/*
1 6 
3

3 10 
5

3 14
6

*/