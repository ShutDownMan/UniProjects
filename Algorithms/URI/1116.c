#include <stdio.h>

int main() {
	int n, i;

	double input[2];

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf("%lf %lf", &input[0], &input[1]);

		if(input[1] == 0){
			printf("divisao impossivel\n");
			continue;
		} else {
			printf("%.1lf\n", input[0]/input[1]);
		}

	}

}