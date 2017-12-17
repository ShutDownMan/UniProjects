#include <stdio.h>

int main(int argc, char const *argv[]) {
	int n;

	scanf("%d", &n);

	int S[n], B[n], A[n];
	int Ss[n], Bs[n], As[n];
	int Sr = 0, Br = 0, Ar = 0;
	int Ssr = 0, Bsr = 0, Asr = 0;

	char nome[10];

	float resultS, resultB, resultA;

	for (int i = 0; i < n; ++i)
	{
		scanf(" %*s ", &nome);
		// Scan tentativas de S, B e A
		scanf("%d %d %d", &S[i], &B[i], &A[i]);
		// Scan de S, B e A sucedidos
		scanf("%d %d %d", &Ss[i], &Bs[i], &As[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		// Sum all tentativas
		Sr += S[i]; Br += B[i]; Ar += A[i];
		// Sum all sucedidas
		Ssr += Ss[i]; Bsr += Bs[i]; Asr += As[i];
	}

	// Divide t/s
	resultS = Ssr/(Sr*1.0); resultB = Bsr/(Br*1.0); resultA = Asr/(Ar*1.0);
	resultS *= 100; resultB *= 100; resultA *= 100;

	printf("Pontos de Saque: %.2lf %%.\n", resultS);
	printf("Pontos de Bloqueio: %.2lf %%.\n", resultB);
	printf("Pontos de Ataque: %.2lf %%.\n", resultA);

	return 0;
}