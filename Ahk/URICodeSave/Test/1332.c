#include <stdio.h>
#define ONE nums[0]
#define TWO nums[1]
#define THREE nums[3]


int main(int argc, char const *argv[]) {
	int cdt, i_cdt, i;
	int errorDist[3] = {0};
	char strin[256], nums[3][16] = {"one", "two", "three"};

	scanf("%d ", &cdt);
	for (i_cdt = 0; i_cdt < cdt; ++i_cdt) {
		scanf(" %s", strin);

		for (i = 0; strin[i]; ++i) {
			errorDist[0] += !(strin[i] - ONE[i]) ? 0 : 1;
			errorDist[1] += !(strin[i] - TWO[i]) ? 0 : 1;
			errorDist[2] += !(strin[i] - THREE[i]) ? 0 : 1;
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