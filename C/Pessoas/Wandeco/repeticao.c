#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i;

	i = 0;
	while(i<=20){
		if (i%2==0){
			printf("%d ", i);
		}
		i++;
	}
	printf("\n");


	return 0;
}