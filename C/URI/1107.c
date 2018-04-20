#include <stdio.h>

int main(int argc, char const *argv[]) {
	int width, height, i, j, continuous, res;
	int heights[10024];

	scanf("%d%d", &width, &height);
	while(width && height) {
		for(i = 0; i < height; ++i) {
			scanf("%d", &heights[i]);
		}

		res = 0;
		for(i = 0; i < width; ++i) {
			continuous = 0;
			for(j = 0; j < height; ++j) {
				if(heights[j] <= i) {
					if(!continuous) {
						res++;
						continuous = 1;
					}
				} else {
					if(continuous) {
						continuous = 0;
					}
				}
			}
		}

		printf("%d\n", res);

		scanf("%d%d", &width, &height);
	}

	return 0;
}