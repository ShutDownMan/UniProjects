#include <stdio.h>
#include <string.h>

#define MAX_STR 1024

void carrega(char *fileName) {
	FILE *f = fopen(fileName, "r+");
	char lineBuffer[MAX_STR] = {0};
	int lineCount = 0;

	while(fgets(lineBuffer, MAX_STR-1, f) != NULL) {
		if(lineCount%2 == 0) {
			printf("*%d %s", lineCount, lineBuffer);
		} else {
			printf("%d %s", lineCount, lineBuffer);
		}
		lineCount++;
	}
	printf("\n");
	fclose(f);
}

int main(void)
{
	char fileName[MAX_STR] = {0};

	printf("Digite o nome do arquivo a ser lido: ");
	fgets(fileName, MAX_STR-1, stdin);
	fileName[strlen(fileName)-1] = '\0';

	carrega(fileName);

	return 0;
}
