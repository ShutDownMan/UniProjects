#include<stdio.h>

int main()
{
	unsigned int in_a, in_b;
	while(scanf("%u %u", &in_a, &in_b) != EOF)
	{
		printf("%u\n", in_a^in_b );
	}
	return 0;
}