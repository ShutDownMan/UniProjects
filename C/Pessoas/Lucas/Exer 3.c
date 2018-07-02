#include <stdio.h>


int bissexto(int a,int b=0){
	if (a%400==0) {
		b=1;
	}
	if((a%4==0)&&(a%100!=0)){
		b=1;
	}
	else {
		b=0;

	}
}

void seguint(int *d, int *m, int a, int b){

	switch(m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		if(d == 31) {
			m++;
			d=0;
		}

	}

	if(((m==4)||(m==6)||(m==9)||(m==11))&&(d==30)){  /// dia 30
		m=m+1;
		d=0;

	}
	if ((m==12)&&(d==31)){
		d=0;
		m=1;
		a=a+1;
	}
	if((b==0)&&(d==28)&&(m==2)){
		d=0;
		m=m+1;
	}
	if((b==1)&&(d==28)&&(m==2)){
		d=d+1;
	}
	if((b==1)&&(d==29)&&(m==2)){
		d=0;
		m=m+1;
	}

	d+=1;

	printf("dia %d do mes %d de %d\n\n",d,m,a);	

}






int main(){
	int n,d,a,m,b;
	printf("Numero de datas que serao digitadas = ");
	scanf("%d",&n);
	for(n;n>0;n--){
		printf("dia,mes e ano\n");
		scanf("%d%d%d",&d,&m,&a);
		bissexto(a,b);
		seguint(d,m,a,b);
		
	}
	return 0;
}
