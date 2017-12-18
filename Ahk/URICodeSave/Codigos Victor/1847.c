#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a-b > b-c) printf(":)\n");
	else
	{
		if(a-b == b-c)
		{
			if(a == b && b == c)	printf(":(\n");
			else if(c > a) printf(":)\n");
			else printf(":(\n");
		}
		else printf(":(\n");
	}
}