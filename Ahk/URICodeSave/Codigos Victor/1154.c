#include<stdio.h>

int main()
{
	int age, count=0, sum=0;

	while(1)
	{
		scanf("%d", &age);
		if(age <= 0) break;
		count++;
		sum += age;
	}

	printf("%.2lf\n", (double)sum/count);

	return 0;
}