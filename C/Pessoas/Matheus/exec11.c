#include <stdio.h>

int inverte(int num) {
	int res;

	for(res = 0; num > 0; num /= 10) {
		res = res*10;
		res += num%10;
	}

	return res;
}

void encripify(int num) {
	int resto;
	num = inverte(num);

	if(num == 0) printf("A");

	for(; num > 0; num /= 10) {
		resto = num%10;
		printf("%c", 'A'+resto);
	}
	printf("\n");
}

int main(void) {
	int num;

	scanf("%d", &num);
	while(num != -1) {
		encripify(num);

		scanf("%d", &num);
	}

	return 0;
}