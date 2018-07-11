#include <stdio.h>

void showIntPointers(int x) {
	int i;
	unsigned char *ptr;

	for(i = 0; i < sizeof(int); ++i) {
		ptr = ((char*)&x) + i;
		printf("[%p] = %02x\n", ptr, *ptr);
	}
}

int main(void) {
	int cdt, x;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d", &x);
		showIntPointers(x);
	}

	return 0;
}