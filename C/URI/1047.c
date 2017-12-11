#include <stdio.h>

int main()
{
	int hour[3], min[3], totalSecs[2];

	// Get h1:m1 h2:m2 imput format
	scanf("%d %d %d %d", &hour[0], &min[0], &hour[1], &min[1]);

	// Calculate seconds equivalent for first and second h:m 
	totalSecs[0] = (hour[0] * 3600) + (min[0] * 60);
	totalSecs[1] = (hour[1] * 3600) + (min[1] * 60);

	// Subtract second from first
	totalSecs[2] = (totalSecs[0] >= totalSecs[1]) ? -(totalSecs[0]-totalSecs[1])+24*3600 : -(totalSecs[0]-totalSecs[1]);

	// Calculate HH:MM equivalent for subtraction result
	hour[2] = (totalSecs[2] / 3600);
	totalSecs[2] -= hour[2] * 3600;

	min[2] = (totalSecs[2] / 60);
	totalSecs[2] -= min[2] * 60;

	// Print result
	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hour[2], min[2]);

}