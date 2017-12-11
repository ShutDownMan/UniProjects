#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
	double a3 = 0, a4 = 0, m3 = 0, m4 = 0, s = 5.5377, sum = 0, med;
	double in_num[6];

	for (int i = 0; i < 6; ++i) {
		scanf("%lf", &in_num[i]);
		sum += in_num[i];
	}

	med = sum/6;

	for(int i = 0; i < 6; ++i) {
		m3 += pow(in_num[i] - med, 3);
		m4 += pow(in_num[i] - med, 4);
	}

	m3 /= 6;
	m4 /= 6;
	a3 = m3/pow(s, 3);
	a4 = m4/pow(s, 4);

	printf("Media: %lf\n", med);

	printf("m3 = %lf\n", m3);

	printf("a3 = %lf\n", a3);

	printf("a4 = %lf\n", a4);

	return 0;
}