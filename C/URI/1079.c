#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	double N1[n], N2[n], N3[n], media[n];

	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf %lf", &N1[i], &N2[i], &N3[i]);

		media[i] = (N1[i] * 2 + N2[i] * 3 + N3[i] * 5) / 10;
	
		printf("%.1lf\n", media[i]);
	}

	return 0;

}