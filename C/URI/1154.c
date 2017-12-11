#include <stdio.h>

int main()
{
	int lastNum, totalSum, divisor = 0;

	double result;

	while (true)
	{
		scanf("%d", &lastNum);

		if(lastNum >= 0){
			totalSum += lastNum;
			divisor++;
		}
		else
		{
			break;
		}
	}

	result = (double)totalSum/(double)divisor;

	printf("%.2lf\n", result);

	return 0;

}