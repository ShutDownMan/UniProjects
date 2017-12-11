#include <stdio.h>
#define XDAY 360


int main(int argc, char const *argv[]) {
	int in_day, in_month, daysToGo;
	int offMonths[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

	char out_result[64];

	while(scanf("%d %d", &in_month, &in_day) != EOF) {
		daysToGo = XDAY - offMonths[in_month-1] - in_day;

		sprintf(out_result, "Faltam %d dias para o natal!", daysToGo); 
		
		if(daysToGo == 1) sprintf(out_result, "E vespera de natal!"); 
		if(daysToGo == 0) sprintf(out_result, "E natal!"); 
		if(daysToGo < 0) sprintf(out_result, "Ja passou!"); 

		printf("%s\n", out_result);
	}

	return 0;
}