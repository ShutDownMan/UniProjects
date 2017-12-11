#include <stdio.h>

int main(int argc, char const *argv[])
{
	int h, m, s, tot;
	scanf("%d", &tot);
	h=tot/3600;
	m=(tot%3600)/60;
	s=tot%3600%60;
	printf("%d:%d:%d\n", h, m, s);
	return 0;
}