#include <stdio.h>

float calcIMC(float peso, float alt);

int IMCToCode(float imc);

void codeMsg(int code);

int main() {
	float peso, alt;

	printf("Digite seu peso: \n");
	scanf("%f", &peso);

	printf("Digite sua altura: \n");
	scanf("%f", &alt);

	codeMsg(IMCToCode(calcIMC(peso, alt)));

	return 0;
}

float calcIMC(float peso, float alt) {
	return peso / (alt*alt);
}

int IMCToCode(float imc) {
	if(imc >= 40) {
		return 8;
	}
	if (imc >= 35)
	{
		return 7;
	}
	if (imc >= 30)
	{
		return 6;
	}
	if (imc >= 25)
	{
		return 5;
	}
	if (imc >= 18.5)
	{
		return 4;
	}
	if (imc >= 17)
	{
		return 3;
	}
	if (imc >= 16)
	{
		return 2;
	}

	return 1;
}

// 16 17 18.5 25 30 35 40

void codeMsg(int code) {
	if(code == 1) {
		printf("Magreza grave\n");
	}
	if(code == 2) {
		printf("Magreza moderada\n");
	}
	if(code == 2) {
		printf("Magreza leve\n");
	}
	if(code == 4) {
		printf("Saudavel\n");
	}
	if(code == 5) {
		printf("Sobrepeso\n");
	}
	if(code == 6) {
		printf("Obeso: grau 1\n");
	}
	if(code == 7) {
		printf("Obeso: grau 2\n");
	}
	if(code == 8) {
		printf("Obeso: grau 3\n");
	}
}