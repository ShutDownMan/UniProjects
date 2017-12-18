#include <stdio.h>

int main (){

	int day[2], hour[2], min[2], sec[2], secT[3]/*total de segundos*/;
	for (int i = 0; i < 2; ++i)
	{
		scanf("%*s %d %d %*s %d %*s %d", &day[i], &hour[i], &min[i], &sec[i]);
		secT[i] = sec[i] + min[i]*60 + hour[i]*3600 + day[i]*86400;
	}
	secT[2] = secT[1]-secT[0];
	printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", secT[2]/86400, secT[2]%86400/3600, secT[2]%3600/60, secT[2]%60);

    return 0;
}