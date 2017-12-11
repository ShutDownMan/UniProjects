#include <iostream>

using namespace std;

int getGDC(int a, int b);

int main() {

	int n = 0;
	int f1 = 0, f2 = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &f1, &f2);

		std::cout << getGDC(f1, f2) << endl;
	}

	return 0;
}

int getGDC(int a, int b) {
	return (b == 0) ? a : getGDC(b, a % b);
}