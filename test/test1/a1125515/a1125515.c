
#include <stdio.h>

int main() {
int q,a,z,e;  
scanf("%d%d",&q,&z);
while(z>0){
	z-=q;
	q+=1;
}
printf("%d",q-1);
}
