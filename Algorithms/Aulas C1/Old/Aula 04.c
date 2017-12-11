/*
z = (x >= 100) && (x %2 == 0);

108
z = (108 >= 100) && (108 %2 == 0);
z = (1) && (0 == 0);
z = (1) && (1);
z = 1;

103
z = (103 >= 100) && (103 %2 == 0);
z = (1) && (1 == 0);
z = (1) && (0);
z = 0;

12
z = (12 >= 100) && (12 %2 == 0);
z = (0) && (0 == 0);
z = (0) && (1);
z = 0;

17
z = (17 >= 100) && (17 %2 == 0);
z = (0) && (1 == 0);
z = (0) && (0);
z = 0;
*/

#include <stdio.h>

int Maior(int a, int b) {
	if(a > b) {
		return a;
	} else {
		return b;
	}
}

int LeapYear(int ano) {
	return ((ano %4 == 0) && (ano %100 != 0)) || (ano %400 == 0);
}

int NumDias(int m, int a) {
	if(m %2 == 0) {
		if(m == 2) {
			return m + LeapYear(a);
		} else {
			return 30;
		}
	} else {
		return 31;
	}

	return -1;
}

/*
31 1
29 2
31 3
30 4
31 5
30 6
31 7
31 8
30 9
31 10
30 11
31 12
*/

int main(int argc, char const *argv[])
{
	int d, m, a;

	scanf("%d %d %d", &m, &a);

	n = NumDias(m, a);

	printf("Numero de dias: %d\n")

	return 0;
}

int main2(int argc, char const *argv[])
{
	int ano;

	scanf("%d", &ano);

	printf("Eh bissexto: %d\n", LeapYear(ano));

	return 0;
}

int main1(int argc, char const *argv[])
{
	int x, y, z;

	scanf("%d %d", &x, &y);

	z = Maior(x, y);

	printf("Maior: %d\n", z);

	return 0;
}