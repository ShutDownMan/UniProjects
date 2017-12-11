#include <stdio.h>
#include <math.h>

#define MAXLENGTH 100
#define MAXWIDTH 100

void printdashes(int length) {
	int i;

	for (i = 0; i < length; ++i) printf("_");
	printf("\n"); 
}

void print2D(int length, int width, int mat[length][width]) {
	int row, col;

	printdashes(width*4);
	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			printf("%3d ", mat[row][col]);
		}
		printf("\n");
	}
}

int sumarray(int length, int width, int mat[length][width]) {
	int row, col, sum;

	sum = 0;
	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			sum += mat[row][col];
		}
	}

	return sum;
}

int lineprod(int row, int length, int width, int mat[length][width]) {
	int col, prod;

	prod = 1;
	for (col = 0; col < width; ++col) {
		prod *= mat[row][col];
	}

	return prod;
}


int linesum(int row, int length, int width, int mat[length][width]) {
	int col, sum;

	sum = 0;
	for (col = 0; col < width; ++col) {
		sum += mat[row][col];
	}

	return sum;
}

int rowprod(int col, int length, int width, int mat[length][width]) {
	int row, prod;

	prod = 1;
	for (row = 0; row < width; ++row) {
		prod *= mat[row][col];
	}

	return prod;
}


int rowsum(int col, int length, int width, int mat[length][width]) {
	int row, sum;

	sum = 0;
	for (row = 0; row < width; ++row) {
		sum += mat[row][col];
	}

	return sum;
}

void makeA(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = (row == col);
		}
	}
	print2D(length, width, mat);
}

void makeB(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = row+1;
		}
	}
	print2D(length, width, mat);
}

void makeC(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = (row+col == length-1);
		}
	}
	print2D(length, width, mat);
}

void makeD(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = col+1;
		}
	}
	print2D(length, width, mat);
}

void makeE(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = col + row*width;
		}
	}
	print2D(length, width, mat);
}

void makeF(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = (row/2)*10 + col*2 + (row%2);
		}
	}
	print2D(length, width, mat);
}

void makeDiamond(int length, int width, int mat[length][width]) {
	int row, col;

	float midlength, midwidth;

	midlength = (length-1)/2.0;
	midwidth = (width-1)/2.0;
	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = (-abs(row-midlength)+midlength+1)/2.0 + (-abs(col-midwidth)+midwidth+1)/2.0;
		}
	}
	print2D(length, width, mat);
}

void makeG(int length, int width, int mat[length][width]) {
	int row, col;

	float midlength, midwidth;

	midlength = (length-1)/2.0;
	midwidth = (width-1)/2.0;
	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = fmin(midlength-abs(row-midlength), midwidth-abs(col-midwidth)) + 1;
		}
	}
	print2D(length, width, mat);
}

void makeH(int length, int width, int mat[length][width]) {
	int row, col;

	int count = 0;
	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			if(row < col) {
				mat[row][col] = 0;
			} else {
				mat[row][col] = mat[row-1][col] + length-row + col + 1;
			}
			if(row == col) {
				mat[row][col] = row + 1;
			}
		}
	}
	print2D(length, width, mat);
}

void makeI(int length, int width, int mat[length][width]) {
	int row, col;

	int count = 0;
	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = (row >= col);
		}
	}
	print2D(length, width, mat);
}

void makeJ(int length, int width, int mat[length][width]) {
	int row, col;

	int count = 0;
	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = (row <= col);
		}
	}
	print2D(length, width, mat);
}

void makeK(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = !((row+col)%2);
		}
	}
	print2D(length, width, mat);
}

void makeL(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			if(col < 2) {
				mat[row][col] = row + 1;
			} else {
				mat[row][col] = mat[row][col-1] + mat[row][col-2];
			}
		}
	}
	print2D(length, width, mat);
}

int main(int argc, char const *argv[]) {
	int width = 5, length = 5;
	int mat[MAXLENGTH][MAXWIDTH] = {0};

	makeA(width, length, mat);
	makeB(width, length, mat);
	makeC(width, length, mat);
	makeD(width, length, mat);
	makeE(width, length, mat);
	makeF(width, length, mat);
	makeG(width, length, mat);
	makeH(width, length, mat);
	makeI(width, length, mat);
	makeJ(width, length, mat);
	makeK(width, length, mat);
	makeL(width, length, mat);

	makeDiamond(width, length, mat);

	printdashes(15);
	printf("Soma linha 0: %d\n", linesum(0, length, width, mat));

	printdashes(16);
	printf("Soma coluna 0: %d\n", rowsum(0, length, width, mat));

	printdashes(18);
	printf("Produto linha 1: %d\n", lineprod(1, length, width, mat));

	printdashes(19);
	printf("Produto coluna 1: %d\n", rowprod(1, length, width, mat));

	printdashes(15);
	printf("Soma matriz: %d\n", sumarray(length, width, mat));

	return 0;
}