/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int edgex, edgey = 0;
    scanf("%d %d", &edgex, &edgey);
    int posx, posy = 0;
    char way;
    char req[100];
    
    while(scanf("%d %d %c", &posx, &posy, &way)!=EOF){
        int direct = 0;
        if(way == "N"){
            direct = 0;
        }
        else if(way == "S"){
            direct = 2;
        }
        else if(way == "E"){
            direct = 3;
        }
        else if(way == "W"){
            direct = 1;
        }
        for(int i = 0;i<100 ;i++){
            scanf("%c", req[i]);
            if(req[i]=="R"){
                direct--;
            }
            else if(req[i]=="L"){
                direct++;
            }
            else{
                if(direct%4==0){
                    posy++;
                }
                else if(direct%4==1){
                    posx--;
                }
                else if(direct%4==2){
                    posy--;
                }
                else if(direct%4==3){
                    posx++;
                }
                if(posx>=edgex||posy>=edgey){
                    printf("%d %d", posx, posy);
                    if(direct%4==0){
                        way = "N";
                    }
                    else if(direct%4==1){
                        way = "W";
                    }
                    else if(direct%4==2){
                        way = "S";
                    }
                    else if(direct%4==3){
                        way = "E";
                    }
                    printf("%c LOST\n", way);
                }
            }
        }
        printf("%d %d", posx, posy);
        if(direct%4==0){
            way = "N";
        }
        else if(direct%4==1){
            way = "W";
        }
        else if(direct%4==2){
            way = "S";
        }
        else if(direct%4==3){
            way = "E";
        }
        printf("%c LOST\n", way);
        }
        
    }
}
