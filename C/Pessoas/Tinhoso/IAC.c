#include<stdio.h>

int main(void){
	int casos, h, m, s, extra, i;

	scanf("%d", &casos);

	for(i = 0; i < casos; i++) {
		scanf("%d %d %d",&h,&m,&s);
		scanf("%d", &extra);

		s += extra;
		while(s >= 60) {
			s-=60;
			m++;
		}
		while(m >= 60) {
			m -= 60;
			h++;
		}

		printf("%d %d %d", h, m, s);
	}

	return 0;
}