#include <stdio.h>

int main(void) {
	int i, cdt;
	int curr, lst, result;

	scanf("%d %d", &cdt, &lst);

	result = 0;

	for (i = 0; i < cdt-1; ++i) {
		scanf("%d", &curr);

		if(lst > curr && !result) result = i+2;

		lst = curr;
	}

	printf("%d\n", result);

	return 0;
}
