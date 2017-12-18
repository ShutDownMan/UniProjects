#include <stdio.h>
void input(int *n);
void invert(int *n);
void declare(int *n);

int main()
{
	int n[20];
	input(n);
	invert(n);
	declare(n);
    return 0;
}

void input(int *n)
{
    int i;
	for ( i = 0; i < 20; ++i)
	{
		scanf("%d", &n[i]);
	}
}

void invert(int *n)
{
    int i;
	for ( i = 0; i < 10; ++i)
	{
		int temp;
		temp = n[i];
		n[i] = n[19-i];
		n[19-i] = temp;
	}
}

void declare(int *n)
{
    int i;
	for ( i = 0; i < 20; ++i)
	{
		printf("N[%d] = %d\n", i, n[i]);
	}
}