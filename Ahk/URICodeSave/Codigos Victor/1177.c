#include <stdio.h>
#include <math.h>

int main ()
{
	int sequence, i = 0, seqCount = 0;

	scanf("%d", &sequence);

	for ( ; i < 1000; ++i)
	{
		printf("N[%d] = %d\n", i, seqCount++);
		if(seqCount == sequence) seqCount = 0;
	}

	return 0;
}
