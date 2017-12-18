#include <stdio.h>

void predigit(char num1, char num2);
void postdigit(char c, int n);

char romanval[1000];
int i = 0;

int main()
{
 	int numero, resto, inteiro;

    char *centenas[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};//Temp
    char *dezenas[]  = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};//Temp
    char *unidades[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};//Temp

    scanf("%d", &numero);

    inteiro = numero/100;
    resto = numero%100;
    switch(inteiro)
    {
        case 1: printf("%s", centenas[1-1]); break;
        case 2: printf("%s", centenas[2-1]); break;
        case 3: printf("%s", centenas[3-1]); break;
        case 4: printf("%s", centenas[4-1]); break;
        case 5: printf("%s", centenas[5-1]); break;
        case 6: printf("%s", centenas[6-1]); break;
        case 7: printf("%s", centenas[7-1]); break;
        case 8: printf("%s", centenas[8-1]); break;
        case 9: printf("%s", centenas[9-1]); break;
    }
    inteiro = resto / 10;
    resto = numero % 10;
	switch(inteiro)
    {
        case 1: printf("%s", dezenas[1-1]); break;
        case 2: printf("%s", dezenas[2-1]); break;
        case 3: printf("%s", dezenas[3-1]); break;
        case 4: printf("%s", dezenas[4-1]); break;
        case 5: printf("%s", dezenas[5-1]); break;
        case 6: printf("%s", dezenas[6-1]); break;
        case 7: printf("%s", dezenas[7-1]); break;
        case 8: printf("%s", dezenas[8-1]); break;
        case 9: printf("%s", dezenas[9-1]); break;
    }
	switch(resto)
    {
        case 1: printf("%s", unidades[1-1]); break;
        case 2: printf("%s", unidades[2-1]); break;
        case 3: printf("%s", unidades[3-1]); break;
        case 4: printf("%s", unidades[4-1]); break;
        case 5: printf("%s", unidades[5-1]); break;
        case 6: printf("%s", unidades[6-1]); break;
        case 7: printf("%s", unidades[7-1]); break;
        case 8: printf("%s", unidades[8-1]); break;
        case 9: printf("%s", unidades[9-1]); break;
    }
    printf("\n");
}