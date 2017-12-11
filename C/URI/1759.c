#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, n;

	scanf("%d", &n);

	for(i = 0; i < n; ++i) {
		if(i == n-1) {
			printf("Ho");
		} else {
			printf("Ho ");
		}
	}

	printf("!\n");

	return 0;
}