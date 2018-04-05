#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int casos, lines, unam;
	char str[32], utilizado[32];

	scanf("%d%*c", &casos);

	while(casos--) {
		scanf("%d%*c", &lines);
		unam = 1;

		scanf("%[^\n]%*c", utilizado);
		lines--;
		while(lines--) {
			scanf("%[^\n]%*c", str);

			if(strcmp(str, utilizado)) {
				unam = 0;
				strcpy(utilizado, "ingles");
			}
		}

		printf("%s\n", utilizado);
	}

	return 0;
}