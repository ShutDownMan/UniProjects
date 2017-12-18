#include <stdio.h>
#include <math.h>


int main(int argc, char const *argv[])
{
	long double c1;
	char str[15];
	scanf("%LE", &c1);
	//sprintf(str, "%+.4LE\n", c1);
	//str[11] = 0;
	printf("%+.4LE\n",c1 );
}
