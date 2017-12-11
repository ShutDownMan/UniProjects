#include <stdio.h>
#include <string.h>

#define GR 6378
#define PI 3.14159

typedef struct {
	char name[32];
	double Latitude;
	double Longitude;
} City;

void scanCities();

void testCities();

double *getEquidistancePoints(char firstCity[], char secondCity[]);

City *getCity(char cityName[]);

City Cities[100];
int main(int argc, char const *argv[])
{
	scanCities();

	testCities();

	return 0;
}

void scanCities() {
	char cityName[32] = {"\0"};
	double latitude = 0;
	double longitude = 0;

	int i;
	for (i = 0; i < 100; ++i)
	{
		scanf("%s", cityName);

		if(strcmp(cityName, "#") != 0) {
			scanf("%lf", &latitude);
			scanf("%lf", &longitude);

			strcpy(Cities[i].name, cityName);
			Cities[i].Latitude = latitude;
			Cities[i].Longitude = longitude;
		} else {
			break;
		}
	}
}

void testCities() {
	char firstCity[32], secondCity[32], thirdCity[32];
	int dist;

	for (int i = 0; i < 100; ++i)
	{
		scanf("%s", firstCity);

		if(strcmp(firstCity, "#") != 0) {
			scanf("%s", secondCity);
			scanf("%s", thirdCity);

			//dist = calcDist(getEquidistancePoints(firstCity, secondCity), thirdCity);

			getEquidistancePoints(firstCity, secondCity);

			//printf("%s is %d km off %s/%s equidistance.\n", thirdCity, dist, firstCity, secondCity);

		} else {
			break;
		}
	}
}

double *getEquidistancePoints(char firstCity[], char secondCity[]) {
	static double equidistancePoints[8];
	double deltaAngle[2];
	City *firstCityData = getCity(firstCity);
	City *secondCityData = getCity(secondCity);

	if(firstCityData && secondCityData) {
		
	}

	return equidistancePoints;
}

City *getCity(char cityName[]) {
	for (int i = 0; i < 100; ++i)
	{
		if(strcmp(Cities[i].name, cityName) == 0) {
			return &Cities[i];
		}
	}
	return NULL;
}



double rad(double degrees) {   
	return (degrees * PI) / 180;
}


/*
Ulm 48.700 10.500

Freiburg 47.700 9.500

Philadelphia 39.883 -75.250

SanJose 37.366 -121.933

Atlanta 33 -84

Eindhoven 52 6

Orlando 28 -82

Vancouver 49 -123

Honolulu 22 -157

NorthPole 90 0

SouthPole -90 0

#

Ulm Freiburg Philadelphia

SanJose Atlanta Eindhoven

Orlando Vancouver Honolulu

NorthPole SouthPole NorthPole

Ulm SanDiego Orlando

NorthPole SouthPole SouthPole

SouthPole NorthPole SouthPole

Ulm Honolulu SouthPole

#
*/