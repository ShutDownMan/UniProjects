#include <stdio.h>
#include <math.h>

int gcd(int x, int y);


int main ()
{
	int x1, y1, x2, y2, z;
	char c;

	scanf("%d", &z);

	for (int i = 0; i < z; ++i)
	{
		scanf("%d %*s %d %c %d %*s %d", &x1, &y1, &c, &x2, &y2);

//		printf("x1 = %d y1 = %d c = %c x2 = %d y2 =%d, ?? = %d", x1, y1, c, x2, y2, '+' );

//		printf("+=%d -=%d *=%d /=%d\n",'+','-','*','/' );

//		scanf("%d%d", &x1, &x2);

//		printf("gcd = %d\n",gcd(x1, x2) );

		switch (c)
		{
			int n, d;

			case 43: //+
				n = x1*y2+x2*y1;
				d = y1*y2;
				printf("%d/%d = %d/%d\n", n, d, n/gcd(n,d), d/gcd(n,d));
				break;

			case 45: //-
				n = x1*y2-x2*y1;
				d = y1*y2;
				printf("%d/%d = %d/%d\n", n, d, n/gcd(n,d), d/gcd(n,d));
				break;

			case 42: //*
				n = x1*x2;
				d = y1*y2;
				printf("%d/%d = %d/%d\n", n, d, n/gcd(n,d), d/gcd(n,d));
				break;

			case 47: // '/'
				n = x1*y2;
				d = x2*y1;
				printf("%d/%d = %d/%d\n", n, d, n/gcd(n,d), d/gcd(n,d));
				break;
		}

	}
	return 0;
}

int gcd(int x, int y)
{
	int a;

 //	printf("in gcd x = %d, y = %d\n", x, y);

	a = y != 0 ? gcd(y, x%y) : x;

	a = a>0 ? a : -a;

	return a;
}
