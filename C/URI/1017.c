#include <stdio.h>

int main() {
	// Input/Output vars
	int travelDur, velMed;

	// Gas used per Km
	double gasPerKm = 12;

	// Get Inputs from console
	scanf("%d %d", &travelDur, &velMed);

	// Calculate gas used
	double gasUsed = (velMed * travelDur) / gasPerKm;

	// Print result
	printf("%.3lf\n", gasUsed);

	return 0;
}