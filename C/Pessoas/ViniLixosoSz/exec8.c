#include <stdio.h.h>

int fazdesenho(int n, char c){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if(i=1 || j=1 || i=n || j=n)
				printf("%c",c );
			else printf(" ");

		}
	}
	printf("\n");
}



int main(){
	int n,c;
	scanf("%d %c", &n,&c);
	while(n !=-1) {
		fazdesenho()
		scanf("%d %c", &n,&c);

	}

}