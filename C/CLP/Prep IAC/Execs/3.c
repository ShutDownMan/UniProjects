#include <stdio.h>

void showDoublePointers(double x) {
	int i;
	unsigned char *ptr;

	for(i = 0; i < sizeof(double); ++i) {
		ptr = ((char*)&x) + i;
		printf("[%p] = %02x\n", ptr, *ptr);
	}
	printf("\n");
}


int main(void) {
	int cdt;
	double x;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%lf", &x);
		showDoublePointers(x);
	}

	return 0;
}