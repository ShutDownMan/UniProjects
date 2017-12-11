#include <stdio.h>
#include <math.h>

typedef struct {
	int x0, y0, x1, y1;
} Rectangle;


void swap(Rectangle *a, Rectangle *b) {
	Rectangle tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(int argc, char const *argv[]) {
	Rectangle r0, r1;
	int width, length;

	while(scanf("%d %d %d %d %d %d %d %d", &r0.x0, &r0.y0, &r0.x1, &r0.y1, &r1.x0, &r1.y0, &r1.x1, &r1.y1) != EOF) {

		if(r0.x0 > r1.x0) swap(&r1, &r0);
		width = r0.x1 - r1.x0;
		width = (r1.x1 > r0.x0) ? width : r1.x1 - r1.x0;
		width = fmin(r0.x1 - r1.x0, r1.x1 - r1.x0);

		//printf("\tfmax: %lf\n", fmax(r0.x0, r0.x1));
		//printf("\tfmin: %lf\n", fmin(r1.x0, r1.x1));

		if(r0.y0 > r1.y0) swap(&r1, &r0);
		length = r0.y1 - r1.y0;
		length = (r1.y1 > r0.y0) ? length : r1.y1 - r1.y0;
		length = fmin(r0.y1 - r1.y0, r1.y1 - r1.y0);

		printf("Width: %d\nLength: %d\n", width, length);
		printf("r1 = (%d, %d) / r1 = (%d, %d)\n", r1.x0, r1.y0, r1.x1, r1.y1);
		printf("y1-y0 = %d\n", r1.y1 - r1.y0);

		if(width == 0 && length == 0) {
			printf("ponto\n");
		} else if((length == 0 && width > 0) || (width == 0 && length > 0)) {
			printf("linha\n");
		} else if(width < 0 || length < 0) {
			printf("inexistente\n");
		} else if(width*length >= 10) {
			printf("grande\n");
		} else {
			printf("adequada\n");
		}
	}
	
	return 0;
}