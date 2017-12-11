#include <stdio.h>

int main() {
	int curNum = 0, gas[3] = {0};

	scanf("%d", &curNum);

	if(curNum < 4 && curNum > 0){
		gas[curNum]++;
	}

	while(curNum != 4) {
		scanf("%d", &curNum);
		if(curNum < 4 && curNum > 0){
			gas[curNum-1]++;
		}
	}

	puts("MUITO OBRIGADO");
	printf("Alcool: %d\n", gas[0]);
	printf("Gasolina: %d\n", gas[1]);
	printf("Diesel: %d\n", gas[2]);

	return 0;
}