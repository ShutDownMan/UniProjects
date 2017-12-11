#include <stdio.h>

int main(int argc, char const *argv[]) {
	int posN = 0, input, i;

	for (i = 0; i < 5; ++i)
	{
		scanf("%d", &input);

		if(input % 2 == 0){
			posN++;
		}
	}

	printf("%d valores pares\n", posN);

	return 0;
}