#include <stdio.h>
#include <math.h>

void swap(int *x, int *y);

int main() {

	int dimen[2];

	printf("Digite abaixo as dimensões da matriz\n");

	// Get array dimensions
	scanf("%d %*[xX ] %d", &dimen[0], &dimen[1]);	

	// Calculate array space needed
	int n = dimen[0] * dimen[1];

	printf("Você deve entrar %d valores\n", n);
	printf("------------\n");

	// Create arrays with calculate space needed
	int input[n], toSort[n], freq[2*n];
	bool swaped = false;

	// Get numbers from console
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		toSort[i] = input[i];
		freq[i] = 0;
		freq[n+i] = 0;
	}

	// Bubble sorting
	do
	{
		swaped = false;

		for (int i = 1; i < n; ++i)
		{
			if (toSort[i-1] > toSort[i])
			{
				swap(&toSort[i-1], &toSort[i]);
				swaped = true;
			}
		}

	} while (swaped);

	printf("Sua matriz ordenada:\n");

	// Print the ordered array
	for (int i = 0; i < dimen[1]; ++i)
	{
		for (int j = 0; j < dimen[0]; ++j)
		{
			printf("%d\t", toSort[(i*dimen[0])+j]);
		}
		printf("\n");
	}

	int curNum = 0;

	// Calculating frequencies
	for (int i = 0; i < n; ++i)
	{
		if(freq[curNum] == 0 && freq[n+curNum] == 0){
			freq[curNum] = toSort[i];
			freq[n+curNum]++;
		}
		else
		{
			if(freq[curNum] != toSort[i]){
				curNum++;
				freq[curNum] = toSort[i];
				freq[n+curNum]++;
			}
			else
			{
				freq[n+curNum]++;
			}
		}
	}

	printf("NUMERO -- FREQUENCIA\n");

	// Printing frequencies
	for (int i = 0; i < n; ++i)
	{
		if (freq[n+i] != 0)
		{
			printf("%d___%d\n", freq[i], freq[n+i]);
		}
	}


	printf("------------\n");
	
	double c, k, at;

	at = toSort[n-1] - toSort[0];

	k = 1 + 3.3 * log10(n);

	c = at / k;

	if(toSort[0] + c*k < toSort[n-1]){
		printf("LIMITE SUPERIOR NAO RESPEITADO\n");
	}

	printf("At = %lf\n", at);
	printf("C = %lf\n", c);
	printf("K = %lf\n", k);

	printf("\n");

	return 0;
}

 void swap(int *x, int *y)
 {
	 int temp = *x;
	 *x = *y;
	 *y = temp;
 }