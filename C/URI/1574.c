#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int cdt, inst, i, p, ind;
	int  instVet[1000] = {0};
	char cmd[24];

	scanf("%d", &cdt);

	while(cdt--) {
		p = ind = 0;

		scanf("%d%*c", &inst);

		for(i = 0; i < inst; ++i) {
			scanf("%[^\n]%*c", cmd);

			if(!strcmp(cmd, "RIGHT")) {
				p++;
				instVet[i] = 1;
			} else if(!strcmp(cmd, "LEFT")) {
				p--;
				instVet[i] = -1;
			} else {
				sscanf(cmd, "%*[^0-9]%d", &ind);
				p += instVet[i] = instVet[--ind];
			}
		}
		printf("%d\n", p);
	}

	return 0;
}