#include <stdio.h>
#include <math.h>
#include <string.h>

int main (){

    char high[20], medium[20], low[20];
    bool onivoro, herbivoro, hematofago;


    scanf(" %s %s %s", &high, &medium, &low);

    onivoro = strcmp (low, "onivoro");

    herbivoro = strcmp(low, "herbivoro");

    hematofago = strcmp(low, "hematofago");

    if (strcmp (high, "vertebrado") ==0)
    {
    	if (strcmp (medium, "ave") == 0)
    	{
    		if (strcmp (low, "carnivoro") == 0)
    		{
    			printf("aguia\n");
    		}

    		if (onivoro == 0)
    		{
    			printf("pomba\n");
    		}
    	}
    	if (strcmp (medium, "mamifero") == 0)
    	{
    		if (onivoro == 0)
    		{
    			printf("homem\n");
    		}

    		if (herbivoro == 0)
    		{
    			printf("vaca\n");
    		}
    	}
    }

    if (strcmp (high, "invertebrado") == 0)
    {
    	if (strcmp(medium, "inseto") == 0)
    	{
    		if (hematofago == 0)
    		{
    			printf("pulga\n");
    		}

    		if (herbivoro == 0)
    		{
    			printf("lagarta\n");
    		}
    	}

    	if (strcmp(medium, "anelideo") == 0)
    	{
    		if (hematofago == 0)
    		{
    			printf("sanguessuga\n");
    		}

    		if (onivoro == 0){
    			printf("minhoca\n");
    		}
    	}
    }

    return 0;
}