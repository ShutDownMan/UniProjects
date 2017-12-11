#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int n, i, j;
	char currentLine[1000];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s[^\n]", currentLine);

		j = 0;
		while(currentLine[j] != '\0') {
			if(isalpha(currentLine[j])) {			
				currentLine[j] += 3;
			}
			j++;
		}
		printf("\n%s\n", currentLine);
	}

	return 0;
}