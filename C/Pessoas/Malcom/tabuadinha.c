#include <stdio.h>
#include <math.h>

int main(){
	int a,i;
	scanf("%d",&a);
	i=1;
	while(i<11){
		printf("%d x %d = %d\n" ,a, i, a*i);
		i++;
	}
}

for(i=1;i<11;i++)