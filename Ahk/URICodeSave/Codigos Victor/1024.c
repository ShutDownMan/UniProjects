#include <stdio.h>
#include <math.h>

int cleanDisplace(char *password);
void reverseArray(char *password, int size);
void displaceHalf(char *password, int size);

int main()
{

	char password[1001];

	int cases, size, i;

	gets(password);

	cases = atoi(password);

	for ( i = 0; i < cases; ++i)
	{
		gets(password);

		size = cleanDisplace(password);

		reverseArray(password, size);

		displaceHalf(password, size);

		printf("%s\n", password );
	}
	return 0;
}

int cleanDisplace(char *password)
{
	int i;
	for (i = 0; password[i] != '\0'; ++i)
	{
		if ((password[i] <= 'z' && password[i] >= 'a') || (password[i] <= 'Z' && password[i]>= 'A'))	password[i] +=3;
	}
	return i-1;
}

void reverseArray(char *password, int size)
{
	int i, j, temp;

	for ( i = 0, j=size ; i <= size/2 ; ++i, --j)
	{
		temp = password[i];
		password[i] = password[j];
		password[j] = temp;
	}
}

void displaceHalf(char *password, int size)
{
	int i;
	for (i = (size+1)/2 ; password[i] != '\0'; ++i)	password[i] -=1;
}