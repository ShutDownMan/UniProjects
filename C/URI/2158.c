#include <stdio.h>

int main(int argc, char const *argv[])
{
	long long int i, fp, fh, vertices, arestas;

	for(i = 1; scanf("%lld %lld", &fp, &fh) != EOF; ++i) {
		arestas = (5*fp + 6*fh)/2;
		vertices = arestas + 2 - (fh+fp);

		printf("Molecula #%lld.:.\n", i);
		printf("Possui %lld atomos e %lld ligacoes\n\n", vertices, arestas);
	}

	return 0;
}