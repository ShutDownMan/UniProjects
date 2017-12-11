
#include <stdio.h>

int main(int argc, char const *argv[]) {
	
	char str1[10024], str2[10024];
	int cdt, i_cdt, i, dist, distSum;

	scanf("%d", &cdt);

	distSum = 0;
	for (i_cdt = 0; i_cdt < cdt; ++i_cdt) {
		scanf("%s %s", str1, str2);

		for (i = 0; str1[i]; ++i) {
			dist = str2[i] - str1[i];

			if(dist < 0) {
				dist += 26;
			}

			distSum += dist;
		}

		printf("%d\n", distSum);

		distSum = 0;
	}

	return 0;
}