#include <stdio.h>
#include <string.h>

int main ()
{
	int g, i ;

	scanf("%d", &g);

	double n, r=0, s=0, c=0;

	for ( i = 0; i < g; ++i)
	{
		char b[2];


		scanf("%lf %c", &n, b);

		if (strcmp(b, "R") == 0) 
		{ 
			r += n; 
		}
		else
		{
		    if(strcmp(b, "C") == 0)
		    {
		        c += n;
		    }
			else
			{
			    s += n;
			}
		}
	}
	printf("Total: %.0lf cobaias\nTotal de coelhos: %.0lf\nTotal de ratos: %.0lf\nTotal de sapos: %.0lf\nPercentual de coelhos: %.2lf %%\nPercentual de ratos: %.2lf %%\nPercentual de sapos: %.2lf %%\n",c+r+s, c, r, s, 100.0*c / (c+r+s), 100.0*r/(c+r+s), 100.0*s/(c+r+s));

    return 0;
}
