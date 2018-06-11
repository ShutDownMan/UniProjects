#include<stdio.h>
int main(int argc, char const *argv[]) {
	int i;

	for(i = 10; i >=0; i--){
		printf("[%d] = %d\n", i, i*i );
	}
	printf("\n");

	return 0;
}