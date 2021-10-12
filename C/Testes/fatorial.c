#include <stdio.h>
#include <time.h>
#include <math.h>

long long int fatorialRec(unsigned long long int n)
{
	if (n == 0)
		return 1;

	return n * fatorialRec(n - 1);
}

long long int fatorialIter(unsigned long long int n)
{
	unsigned long long int res = 1;

	for(int i = n; i; i--)
		res *= i;
		

	return res;
}

void timeFatorialRec(int n) {
	clock_t begin = clock();

	for (int i = 0; i < n; i++)
		fatorialRec(30);

	clock_t end = clock();
	double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("time spent = %lf\n", timeSpent);
}

void timeFatorialIter(int n) {
	clock_t begin = clock();

	for (int i = 0; i < n; i++)
		fatorialIter(30);

	clock_t end = clock();
	double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("time spent = %lf\n", timeSpent);
}

int main(void)
{
	unsigned long long int iterCount = 1000000000;

	// printf("%lld! = %d\n", 31, fatorialIter(31));

	for (int i = 1; i < iterCount; i *= 2)
		printf("%d\n", i);

	// for (int i = 1; i < iterCount; i *= 2)
	// 	timeFatorialRec(i);

	// puts("--------------");

	// for (int i = 1; i < iterCount; i *= 2)
	// 	timeFatorialIter(i);

	return 0;
}

/*
[0.000001, 0.000001, 0.000002, 0.000002, 0.000003, 0.000006, 0.000011, 0.000022, 0.000044, 0.000087, 0.000162, 0.000299, 0.000583, 0.001147, 0.002140, 0.003606, 0.005557, 0.009469, 0.018406, 0.036950, 0.073453, 0.146819, 0.293320, 0.631125, 1.310695, 2.353630, 5.503026, 10.752140, 19.182081, 38.987392]
--------------
[0.000001, 0.000000, 0.000000, 0.000001, 0.000001, 0.000002, 0.000003, 0.000007, 0.000013, 0.000027, 0.000053, 0.000106, 0.000212, 0.000424, 0.000848, 0.001701, 0.003398, 0.006870, 0.013841, 0.027788, 0.055476, 0.109657, 0.217588, 0.436480, 0.872214, 1.744405, 3.497994, 6.980379, 13.985495, 27.925366]

[1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912]
*/