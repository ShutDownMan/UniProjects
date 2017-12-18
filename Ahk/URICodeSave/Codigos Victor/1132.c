#include <stdio.h>
#include <math.h>

#define open int
#define sesame main

open sesame()
{
	int x, y, i=0, sum=0;
	
	scanf("%d%d", &x, &y);
	
	
	
	for(i=fmin(x, y); i<=fmax(x, y); i++)
	{
		if (i%13!=0) sum += i;
	}	
	printf("%d\n",sum);
	
	return 0;
}