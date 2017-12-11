#include <stdio.h>
#define define ☺
#define open int
#define the main
#define checka ()

open the checka {
	printf("Just No!\n");
}

int SecsToHHMMSS(int argc, char const *argv[]) {
	int in_sec;
	int sec, min, hour;

	printf("Entre com os segundos decorridos: \n");
	scanf("%d", &in_sec);

	hour = in_sec/3600;
	in_sec %= 3600;

	min = in_sec/60;
	in_sec %= 60;

	sec = in_sec;

	printf("%d:%d:%d\n", hour, min, sec);

	return 0;
}

int HHMMSSToSecs(int argc, char const *argv[]) {
	int in_hour, in_min, in_sec;
	int secs = 0;

	printf("Entre com hora min segundo: \n");
	scanf("%d %d %d", &in_hour, &in_min, &in_sec);

	secs += in_hour *3600;
	secs += in_min *60;
	secs += in_sec;

	printf("Segundos decorridos: %d\n", secs);

	return 0;
}

int IMC(int argc, char const *argv[]) {
	double in_altura, in_peso;
	double imc;

	printf("Entre com uma altura: \n");
	scanf("%lf", &in_altura);
	printf("Entre com um peso\n");
	scanf("%lf", &in_peso);

	imc = in_peso/(in_altura*in_altura);

	printf("IMC = %.3lf\n", imc);

	return 0;
}

int Ah5Desgrama(int argc, char const *argv[]) {
	double in_x, in_y, z, w;
	double one_over_x, x_over_y;

	scanf("%lf %lf", &in_x, &in_y);

	one_over_x = 1/in_x;
	x_over_y = in_x/in_y;

	z = 1 + one_over_x;

	for (int i = 0; i < 3; ++i) {
		z = one_over_x * z + 1;
	}

	w = x_over_y - (in_x + x_over_y*x_over_y)/(in_x - x_over_y*x_over_y);
	
	printf("z = %.3lf\n", z);
	printf("w = %.3lf\n", w);

	return 0;
}