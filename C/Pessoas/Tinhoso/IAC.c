#include<stdio.h>

int main(){
	int casos,h,m,s,extra,i;
	scanf("%d", &casos);
	for(i=0;i<casos;i++){
		scanf("%d %d %d",&h,&m,&s);
		scanf("%d",&extra);
		s+=extra;
		if(s>60){
			s-=60;
			m+=1;
		}if(m>60){
			m-=60;
			h+=1;
		}
		printf("%d %d %d", h, m, s);
		return 0;
		}
}