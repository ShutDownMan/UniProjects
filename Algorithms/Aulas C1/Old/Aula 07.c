#include <stdio.h>

int main0(int argc, char const *argv[])
{
	int i;
	for (i = 0; i < 10; ++i)
	{
		printf("%d\n", i);
	}

	return 0;
}

int main1(int argc, char const *argv[])
{
	int i, n;

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		printf("%d\n", i);
	}

	return 0;
}

int main2(int argc, char const *argv[])
{
	int i, n;

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		printf("%d - %d\n", i, (n-1)-i);
	}
	return 0;
}

int main3(int argc, char const *argv[]) {
	int i, n, curr, sum;

	scanf("%d", &n);

	sum = 0;
	for (i = 0; i < n; ++i) {
		scanf("%d", &curr);

		if (curr %2 == 0) {
			sum++;
		}
	}

	printf("PARES = %d\n", sum);

	return 0;
}

int main(int argc, char const *argv[]) {
	int curr, i, sumPar, sumT;

	sumPar = 0;
	sumT = 0;
	i = 0;
	while(1) {
		scanf("%d", &curr);

		if(curr == 0) break;

		if(curr %2 == 0) sumPar++;
		sumT += curr;
		i++;
	}

	printf("PARES = %d\n", sumPar);
	printf("SOMA = %d\n", sumT);
	printf("ITERACOES = %d\n", i);
	return 0;
}