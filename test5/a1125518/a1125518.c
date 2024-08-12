#include <stdio.h>

int dir(char f){
    if(f=='N') return 0;
         else if(f=='E') return 1;
         else if(f=='S') return 2;
         else return 3;
}

int main()
{
    int mx,my;
    scanf("%d %d",&mx,&my);
    int map[my][mx][4];
    int sx,sy;
    char f,d;
    int ff,l;
    while(scanf("%d %d %c",&sx,&sy,&f)!=EOF){
        getchar();
        l=0;
        ff=dir(f);
         while(scanf("%c",&d)!=EOF){
            //轉彎
            if(d=='R'){
                ff++;
                if(ff==4) ff=0;
                continue;
            }else if(d=='L'){
                ff--;
                if(ff==-1) ff=3;
                continue;
            }else if(d=='F'){
                    if(ff==0){
                        if(map[sy][sx][0]!=1) sy++;
                        if(sy>my){
                            sy--;
                            map[sy][sx][0]=1;
                
                            if(l==0) printf("%d %d N LOST\n",sx,sy);
                            l=1;
                        }
                    }
                    if(ff==1){
                        if(map[sy][sx][1]!=1) sx++;
                        if(sx>mx){
                            sx--;
                            map[sy][sx][1]=1;
                            
                             if(l==0) printf("%d %d E LOST\n",sx,sy);
                            l=1;
                        }
                    
                    }
                    if(ff==2){
                        
                        if(map[sy][sx][2]!=1) sy--;
                        if(sy<0){
                             sy++;
                            map[sy][sx][2]=1;
                           
                            if(l==0)  printf("%d %d S LOST\n",sx,sy);
                             l=1;
                        }
                    
                    }
                    if(ff==3){
                        
                        if(map[sy][sx][3]!=1) sx--;
                        if(sx<0){
                            sx++;
                            map[sy][sx][3]=1;
                            l=1;
                            if(l==0) printf("%d %d W LOST\n",sx,sy);
                             l=1;
                        }
                    
                    
                    }
            }
            //printf("%d %d %d\n",sx,sy,ff);
        }
        if(l=0){
        printf("%d %d ",sx,sy);
        if(ff==0) printf("N\n");
        if(ff==1) printf("E\n");
        if(ff==2) printf("S\n");
        if(ff==3) printf("W\n");
        }
    }    

    return 0;
}
