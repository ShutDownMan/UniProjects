
#include <stdio.h>
#include <math.h>
void printanvezes(int a,char doce);
int main(){
	int a;
	char doce;
	scanf("%d %c",&a,&doce);
	printanvezes(a,doce);
}
void printanvezes(int a,char doce){
	int i;
	for (i=0;i<a;i++){
		putchar(doce);
	}
	putchar('\n');

}
