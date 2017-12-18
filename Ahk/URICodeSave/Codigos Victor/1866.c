#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n, a, i;
	scanf("%d", &n);
	for ( i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		printf("%d\n",a%2 );
	}
	return 0;
}
