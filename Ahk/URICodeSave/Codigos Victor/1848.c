#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char caw[10];
	int i, j, sum, sum2;

	for (i = 0; i < 3; ++i)
	{
		sum2 = 0;
		gets(caw);
		while(caw[0] != 'c')
		{
			sum = 0;
			for (j = 0; j < 3; ++j)
			{
				int aux;
				caw[j] == '*' ? (aux = 1) : (aux = 0);
				sum = sum*2 + aux;
//				printf("aux = %d, sum = %d\n",aux, sum );
			}
			sum2 += sum;
			gets(caw);
		}
		printf("%d\n",sum2);
	}
}