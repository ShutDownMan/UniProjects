#include <stdio.h>
#define ONE nums[0]
#define TWO nums[1]
#define THREE nums[2]


int main(int argc, char const *argv[]) {
	int cdt, i_cdt, i;
	int errorDist[3] = {0};
	char string[256], nums[3][16] = {"one", "two", "three"};

	scanf("%d ", &cdt);
	for (i_cdt = 0; i_cdt < cdt; ++i_cdt) {
		scanf(" %s", string);

		for (i = 0; string[i]; ++i) {
			errorDist[0] += !!(string[i] - ONE[i]);
			errorDist[1] += !!(string[i] - TWO[i]);
			errorDist[2] += !!(string[i] - THREE[i]);
		}
		
		if(i <= 3) {
			if(errorDist[0] < 2) {
				printf("1\n");
			}

			if(errorDist[1] < 2) {
				printf("2\n");
			}
		} else {
			if(errorDist[2] < 2) {
				printf("3\n");
			}
		}

		errorDist[0] = errorDist[1] = errorDist[2] = 0;
	}

	return 0;
}