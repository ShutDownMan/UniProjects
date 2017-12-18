#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int a, b, r, q;
	scanf("%d %d", &a, &b);
	q = a / b;
//	printf("q = %d\n",q );
	r = a - b * q;
	if (r<0)
	{
		if(!q)
		{
			q++;
			r = a - b * q;
			if(r<0) q-=2;
			r = a - b * q;
		} else q = q/fabs(q) * (fabs(q)+1);

		r = a - b * q;
	}
	printf("%d %d\n", q, r );
	return 0;
}