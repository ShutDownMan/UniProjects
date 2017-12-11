#include <stdio.h>

int main(int argc, char const *argv[]) {
	int in_n, in_startNum, in_qSum, sum, cdt, i, j;

	scanf("%d", &in_n);

	for (cdt = 0; cdt < in_n; ++cdt) {
		scanf("%d %d", &in_startNum, &in_qSum);

		sum = 0; j = 0;
		for(i = in_startNum; j < in_qSum; ++i) {
			if(i %2 != 0) {
				sum += i;
				i++; j++;
			}
		}

		printf("%d\n", sum);
	}


	return 0;
}