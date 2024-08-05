#include<stdio.h>


int Ugly(int a){
    int box[]={2,3,5};
    for(int i=0;i<sizeof(box)/sizeof(box[0]);i++){
        while(a%box[i]==0)
            a=a/box[i];
    }
    if(a==1)
    return 1;
    else
    return 0;
}

int main(){
    int input,Un=1;
    scanf("%d",&input);
    for(int i=1;i<input;i++){
        do{
            Un++;
        }
        while(!Ugly(Un));
    }
    printf("%d",Un);
    return 0;
}

