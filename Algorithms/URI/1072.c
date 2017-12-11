#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, i, curr, n_in = 0;

	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d", &curr);

		if(curr >= 10 && curr <= 20) {
			n_in++;
		}
	}

	printf("%d in\n", n_in);
	printf("%d out\n", n-n_in);

	return 0;
}