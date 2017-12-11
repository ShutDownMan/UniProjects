#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAXL 100
#define MAXC 100

int loadmatriz(char *fn,int m[][MAXC],int *nl,int *nc){
	FILE* f;
	int i,j;
	if(!(f=fopen(fn,"r"))) return 0;
	fscanf(f,"%d %d",nl,nc);
	for(i=0;i<*nl;i++){
		for(j=0;j<*nc;j++)
		fscanf(f,"%d",&m[i][j]);
	}
	fclose(f);
	return 1;
}

int isidentidade(int m[][MAXC],int nl,int nc){
	int i,j;
	for(i=0;i<nl;i++)
		for(j=0;j<nc;j++)
			if(i == j){
					if(m[i][j] != 1) return 0;
			} else {
				if(m[i][j] != 0) return 0;
			}
	return 1;
}

int ispermutacao(int m[][MAXC],int nl,int nc){
	int i,j;
	for(i=0;i<nl;i++)
		for(j=i;j<nc;j++)
			if(m[i][j] != m[j][i])
				return 0;
	return 1;
}

void printmat(FILE *f,int m[][MAXC],int nl,int nc){
   int i,j;
	for(i=0;i<nl;i++){
		for(j=0;j<nc;j++)
			fprintf(f,"%5d",m[i][j]);
		fprintf(f,"\n");
	}
}

int magic(int m[][maxc],int nl,int nc,int vet[]){
	int i,j,s;
	for(i=s=0;i<nl;i++)
	   for(j=0;j<nc;j++)
			vet[i] = 0;
	if(nl == nc){
		 s+=m[i][j];
		vet[i]+=m[i][j];
		s+=m[i][nc-i-1];
	}
}

int diagprincsoma(int m[][maxc], int nl, int nc, int vet[]){
	int i, sum;

	if(nl != nc) {
		return NAN;
	}

	sum = 0;
	for (i = 0; i < nl; ++i) {
		sum += m[i][i];
	}

	return sum;
}

void processa(FILE *f,char *fn,int m[][MAXC],int nl,int nc){
	int i,j;
	fprintf(f, "%s\n",fn);
	printmat(f,m,nl,nc);
	fprintf(f,"Quadrada: %s\n",(nl == nc)? "SIM" : "NAO");
	fprintf(f,"Identidade: %s\n",(isidentidade(m,nl,nc)? "SIM" : "NAO"));
	fprintf(f,"Permutaçao: %s\n",(ispermutacao(m,nl,nc)? "SIM" : "NAO"));
}


int main(){
	FILE *f, *frelat;
	char fn[MAX];
	int m[MAX][MAXC],nc,nl;
	if(!(f = fopen("matrizes.txt","r"))) return 1;
	if(!(frelat = fopen("relat.txt","w"))) return 2;
	while(! feof(f)){
		fscanf(f,"%[^\n]%*c",fn);
		if(loadmatriz(fn,m,&nl,&nc)){
			processa(frelat,fn,m,nl,nc);
		}else{
			fprintf(frelat,"%s\n arquivo não existe\n",fn);
		}
	}
	fclose(f);
	fclose(frelat);
	system("PAUSE");
	return 0;
}