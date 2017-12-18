#include <stdio.h>
#define HAVELOWERCASE reqs[0]
#define HAVEUPPERCASE reqs[1]
#define HAVENUMBER reqs[2]


int main(int argc, char const *argv[]) {
	int i;
	char pass[1024], reqs[3];

	while(!feof(stdin)) {
		gets(pass);

		HAVELOWERCASE = HAVEUPPERCASE = HAVENUMBER = 0;

		for (i = 0; pass[i]; ++i) {

			if(pass[i] >= 'a' && pass[i] <= 'z') {
				HAVELOWERCASE = 1;
				//printf("-> HL ");
				continue;
			}

			if(pass[i] >= 'A' && pass[i] <= 'Z') {
				HAVEUPPERCASE = 1;
				//printf("-> HU ");
				continue;
			}

			if(pass[i] >= '0' && pass[i] <= '9') {
				HAVENUMBER = 1;
				//printf("-> HN ");
				continue;
			}

			HAVELOWERCASE = HAVEUPPERCASE = HAVENUMBER = 0;
			break;
		}

		if(HAVELOWERCASE && HAVEUPPERCASE && HAVENUMBER) {
			if(i < 6 || i > 32) {
				printf("Senha invalida.\n");
			} else {
				printf("Senha valida.\n");
			}
		} else {
			printf("Senha invalida.\n");
		}
	}

	return 0;
}#include <stdio.h>
#define HAVELOWERCASE reqs[0]
#define HAVEUPPERCASE reqs[1]
#define HAVENUMBER reqs[2]


int main(int argc, char const *argv[]) {
	int i;
	char pass[1024], reqs[3];

	while(!feof(stdin)) {
		gets(pass);

		HAVELOWERCASE = HAVEUPPERCASE = HAVENUMBER = 0;

		for (i = 0; pass[i]; ++i) {

			if(pass[i] >= 'a' && pass[i] <= 'z') {
				HAVELOWERCASE = 1;
				//printf("-> HL ");
				continue;
			}

			if(pass[i] >= 'A' && pass[i] <= 'Z') {
				HAVEUPPERCASE = 1;
				//printf("-> HU ");
				continue;
			}

			if(pass[i] >= '0' && pass[i] <= '9') {
				HAVENUMBER = 1;
				//printf("-> HN ");
				continue;
			}

			HAVELOWERCASE = HAVEUPPERCASE = HAVENUMBER = 0;
			break;
		}

		if(HAVELOWERCASE && HAVEUPPERCASE && HAVENUMBER) {
			if(i < 6 || i > 32) {
				printf("Senha invalida.\n");
			} else {
				printf("Senha valida.\n");
			}
		} else {
			printf("Senha invalida.\n");
		}
	}

	return 0;
}