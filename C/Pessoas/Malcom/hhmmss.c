#include<stdio.h>

int main() {
	int s, m, h, st;
	scanf("%d", &st);
	h = st/3600;
	m = st%3600/60;
	s = st%3600%60;

	printf("%d:%d:%d\n", h, m, s);

}