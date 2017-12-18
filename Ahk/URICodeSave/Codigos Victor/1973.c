#include <stdio.h>
#include <stdlib.h>

int main()
{
	int farms, *lambs, i, highest = 0;
	long long unsigned int sum =0, count = 0;

	scanf("%d", &farms);

	lambs = malloc(sizeof(int)*farms);

	for (i = 0; i < farms; ++i)
	{
		scanf("%llu", &lambs[i]);
		sum += lambs[i];
//		printf("DEBUGG = farm[%d] = [%d] lambs\n", i, lambs[i]);
	}
	i=0;

	while(i>=0 && i<farms)
	{
		if(lambs[i])
		{
			lambs[i]--;
//			printf("before = farm[%d] = [%d] lambs\n", i, lambs[i]);
			lambs[i]+1 & 1 ? i++ : i--;
			count++;
		}else
		 {
		 	i--;
		 }
		if(i>highest && i < farms) highest = i;
//		printf("after = farm[%d] = [%d] lambs\n", i, lambs[i]);
	}
	printf("%d %llu\n", highest+1, sum - count );
}