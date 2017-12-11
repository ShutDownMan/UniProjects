#include <stdio.h>

int main()
{
	int highestNum[2] = { 0, 0 }, curNum, i;

	for (i = 0; i < 100; ++i)
	{
		scanf("%d", &curNum);

		if(curNum > highestNum[0]){
			highestNum[0] = curNum;
			highestNum[1] = i + 1;
		}
	}

	printf("%d\n", highestNum[0]);
	printf("%d\n", highestNum[1]);

	return 0;
}