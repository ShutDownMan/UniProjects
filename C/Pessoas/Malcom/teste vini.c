#include <stdio.h>
int main() {
	int x;

	scanf("%d",&x);

	x -= (x%3)-3;

	printf("%d",x);

	return 0;
}