#include <stdio.h>

int contemNumero(int num, int vet[], int tamanho) {
	int i;

	/// para cada elemento no vetor
	for(i = 0; i < tamanho; ++i) {
		/// testa se elemento atual é igual a número
		if(num == vet[i]) {
			/// se for, retorna 1
			return 1;
		}
	}

	/// se não, retorna 0
	return 0;
}

void lerConjunto(int vet[]) {
	int tamanho, num;

	/// enquanto tamanho do vetor não for 10
	for(tamanho = 0; tamanho < 10;) {
		/// lê da entrada padrão um número
		printf("vet[%d] = ", tamanho);
		scanf("%d", &num);

		/// testa se número jã não está presente no vetor
		if(!contemNumero(num, vet, tamanho)) {
			/// se NÃO estiver, adiciona ao vetor
			vet[tamanho] = num;
			/// atualiza tamanho do vetor
			tamanho++;
		}
	}
}

void uniao(int vetX[], int vetY[], int vetXuY[], int *tamVetXuY) {
	int i;

	/// para cada elemento nos vetores X e Y
	for(i = *tamVetXuY = 0; i < 10; ++i) {
		/// Se o vetor união já não contém o elemento atual de X
		if(!contemNumero(vetX[i], vetXuY, *tamVetXuY)) {
			/// adiciona no final do vetor união
			vetXuY[*tamVetXuY] = vetX[i];
			/// Atualiza tamanho do vetor união
			(*tamVetXuY)++;
		}
		/// Se o vetor união já não contém o elemento atual de Y
		if(!contemNumero(vetY[i], vetXuY, *tamVetXuY)) {
			/// adiciona no final do vetor união
			vetXuY[*tamVetXuY] = vetY[i];
			/// Atualiza tamanho do vetor união
			(*tamVetXuY)++;
		}
	}
}

void printaVet(int vet[], int tamanho) {
	int i;

	/// para cada elemento no vetor
	for(i = 0; i < tamanho; ++i) {
		/// printa o elemento na tela
		printf("vet[%d] = %d\n", i, vet[i]);
	}
}

int main(void) {
	int vetX[10], vetY[10], vetXuY[20];
	int tamVetXuY;

	/// lê os vetores
	lerConjunto(vetX);
	printf("------------------\n");
	lerConjunto(vetY);
	printf("------------------\n");

	/// calcula a união deles e guarda no vetXuY
	uniao(vetX, vetY, vetXuY, &tamVetXuY);

	/// printa na tela o vetor
	printaVet(vetXuY, tamVetXuY);
	printf("------------------\n");

	return 0;
}