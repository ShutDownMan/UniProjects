#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	unsigned int n, in1, in2, i;
	char name[2][105], game[100];
	scanf("%u", &n);
	for ( i = 0; i < n; ++i)
	{
		scanf("%s %s %s %*s %u %u", &name[0], game, &name[1], &in1, &in2 );
		( ( !( (in1+in2)%2 ) && strcmp(game, "IMPAR") ) || ((in1+in2)%2 && !strcmp(game, "IMPAR"))) ? printf("%s\n",name[0] ) : printf("%s\n", name[1]);
	}
	return 0;
}
