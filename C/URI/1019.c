#include <stdio.h>

int main(void) {
	// Initialize Input/Output
	int inputVal, totalSecs, secs, mins, hours;

	// Get total seconds
	scanf("%d", &inputVal);

	totalSecs = inputVal;

	hours = totalSecs / 3600;
	totalSecs -= (hours*3600);

	mins = totalSecs / 60;
	totalSecs -= (mins*60);

	secs = totalSecs;

	printf("%d:%d:%d\n", hours, mins, secs);

	return 0;
}