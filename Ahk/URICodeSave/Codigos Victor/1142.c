#include <stdio.h>
#include <math.h>


int main ()
{
	int x, n=1;

	scanf("%d", &x);

	for (int i = 1; i <= x; ++i)
	{
		printf("%d %d %d PUM\n", n++-2, n++, n++ +2);
		n++;
	}


	return 0;
}
