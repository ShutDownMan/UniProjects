#include <stdio.h>

int max(int a, int b);
int min(int a, int b);

int main() {
	int h1, h2;
	int m1, m2;

	scanf("%d %d %d %d", &h1, &h2, &m1, &m2);
	printf("%d %d", max(h1, h2) + min(m1, m2), min(h1, h2) * max(m1, m2));
}

int max(int a, int b){
	/* if(a > b)
		return a;
	return b; */
	return(a > b)? a : b;
}

int min(int a, int b) {
	/* if(a < b)
		return a;
	return b; */
	return(a < b)? a : b;
}