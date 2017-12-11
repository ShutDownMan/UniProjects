#include <stdio.h>
#include <math.h>

int calcNotas(int din);

int calcMoedas(int din);

int notasVal[6] = {10000, 5000, 2000, 1000, 500, 200};
int moedasVal[6] = {100, 50, 25, 10, 5, 1};

int main() {
	int din = 0;
	int notas[6], moedas[6];

	float input;

	scanf("%f", &input);

	din = round(input * 100);

	printf("NOTAS:\n");
	din = calcNotas(din);

	printf("MOEDAS:\n");
	din = calcMoedas(din);

	return 0;
}

int calcNotas(int din) {
	int i;

	for(i = 0, din = 10; i < 6; ++i)
	{
		printf("%d nota(s) de R$ %d,00\n", din/notasVal[i], notasVal[i]/100);
		din %= notasVal[i];
	}

	return din;
}

int calcMoedas(int din){
	int i;

	printf("%d moeda(s) de R$ 1,00\n", din/moedasVal[0]);
	din %= moedasVal[0];

	for(i = 1; i < 6; ++i)
	{
		printf("%d moeda(s) de R$ 0,%02d\n", din/moedasVal[i], moedasVal[i]);
		din %= moedasVal[i];
	}

	return din;
}
