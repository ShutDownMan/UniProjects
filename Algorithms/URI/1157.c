#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	int i=1;

	scanf("%d", &n);

	for (i = 1; i <= n; ++i) {
		if(n%i == 0){
			printf("%d\n", i);
		}
	}

	return 0;
}