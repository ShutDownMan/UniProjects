#include <stdio.h>
#include <math.h>

float Calculate(float a, float b, char op) {
	if(op == '+') return a+b;

	if(op == '-') return a-b;

	if(op == '*') return a*b;

	if(op == '/' && b != 0) return a/b;

	if(op == '^') return pow(a, b);

	return 0;
}

float Processa(float a, char op1, float b, char op2, float c) {
	float result;

	if(op2 == '^') {
		result = Calculate(b, c, op2);
		result = Calculate(a, result, op1);
		return result;
	}
	if(op2 == '^') {
		result = Calculate(a, b, op1);
		result = Calculate(result, c, op2);
		return result;	
	}

	if(op1 == '*' || op1 == '/') {
		result = Calculate(a, b, op1);
		result = Calculate(result, c, op2);	
		return result;
	}

	result = Calculate(b, c, op2);
	result = Calculate(a, result, op1);
	return result;
}

int main(int argc, char const *argv[])
{
	float in_a, in_b, in_c;
	float out_result;	
	char in_operador, in_operador2;

	scanf("%f %c %f %c %f", &in_a, &in_operador, &in_b, &in_operador2, &in_c);

	out_result = Processa(in_a, in_operador, in_b, in_operador2, in_c);

	printf("> %g\n", out_result);

	return 0;
}