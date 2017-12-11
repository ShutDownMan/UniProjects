#include <stdio.h>

int main()
{
	int day[3], hour[3], min[3], secs[3], totalSecs[3];

	// Get first day inputs
	scanf("%*s %d", &day[0]);
	scanf("%d %*s %d %*s %d", &hour[0], &min[0], &secs[0]);

	// Get second day input
	scanf("%*s %d", &day[1]);
	scanf("%d %*s %d %*s %d", &hour[1], &min[1], &secs[1]);

	// Calculate the seconds equivalent for first day and second
	totalSecs[0] = (secs[0]) + (60 * min[0]) + (3600 * hour[0]) + (86400 * day[0]);
	totalSecs[1] = (secs[1]) + (60 * min[1]) + (3600 * hour[1]) + (86400 * day[1]);

	// Subtract second from first
	totalSecs[2] = totalSecs[1] - totalSecs[0];

	// Calculate DD HH:MM:SS equivalent
	day[2] = totalSecs[2] / 86400;
	totalSecs[2] -= (day[2] * 86400);

	hour[2] = totalSecs[2] / 3600;
	totalSecs[2] -= (hour[2] * 3600);

	min[2] = totalSecs[2] / 60;
	totalSecs[2] -= (min[2] * 60);

	secs[2] = totalSecs[2];

	// Print results
	printf("%d dia(s)\n", day[2]);
	printf("%d hora(s)\n", hour[2]);
	printf("%d minuto(s)\n", min[2]);
	printf("%d segundo(s)\n", secs[2]);
}