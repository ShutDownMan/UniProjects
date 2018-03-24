#ifndef RECURSIVEFUNCTIONS_H
#define RECURSIVEFUNCTIONS_H

/// Entrada: um inteiro n
/// Pré-condição: n >= 0
/// Pós-condição: printa na saida de dados padrão os valores até n
void printToN(int n);

/// Entrada: un inteiro n
/// Pré-condição: nenhuma
/// Pós-condição: printa na saida de dados padrão todos os valores a partir de n
void printFromN(int n);

/// Entrada: um inteiro n
/// Pré-condição: n >= 0
/// Pós-condição: retorna a soma de todos os inteiros até n
int sumFromN(int n);

/// Entrada: um inteiro n
/// Pré-condição: n >= 0
/// Pós-condição: retorna o fatorial de n
long long int fac(int n);

/// Entrada: um inteiro n
/// Pré-condição: n >= 0
/// Pós-condição: retorna o superfatorial de n
long long int superFactorial(int n);

/// Entrada: um inteiro n
/// Pré-condição: n >= 0
/// Pós-condição: retorna o fatorial exponencial de n
long long int expFac(int n);

/// Entrada: um inteiro n
/// Pré-condição: m >= 0
/// Pós-condição: retorna o valor catalão de n
long long int catalan(int n);

/// Entrada: um vetor de char e um inteiro indicando tamanho do vetor
/// Pré-condição: nenhuma
/// Pós-condição: retorna se o vetor de char fornecido é palindromo
int isPalim(char* str, int length);

/// Entrada: um vetor de char com os simbotos originais, um de buffer e um inteiro indicando nível
/// Pré-condição: nenhuma
/// Pós-condição: printa na saída de dados padrão todos os subsets dentro do set fornecido
void printSubsets(char base[], char subset[], int level);

/// Entrada: dois inteiros (m e n)
/// Pré-condição: nenhuma
/// Pós-condição: retorna o valor calculado para os dois inteiros
long long int ackerman(int m, int n);

/// Entrada: um inteiro n
/// Pré-condição: nenhuma
/// Pós-condição: retorna a soma dos digitos do inteiro
int digSum(int n);

/// Entrada: um vetor de inteiros e seu tamanho
/// Pré-condição: nenhuma
/// Pós-condição: inverte valores do vetor fornecido
void invertVet(int length, int vet[]);

// HELPER FUNCTIONS //

/// Entrada: um vetor de inteiros e seu tamanho
/// Pré-condição: nenhuma
/// Pós-condição: lê da entrada de dados padrão inteiros e adiciona-os ao vetor
void readVet(int *length, int vet[]);

/// Entrada: um vetor de inteiro e seu tamanho
/// Pré-condição: nenhuma
/// Pós-condição: printa na saida de dados padrão um vetor de inteiro
void printVet(int length, int vet[]);

/// Entrada: dois ponteiros de inteiro
/// Pré-condição: nenhum dos parâmetros sejam nulos
/// Pós-condição: troca valores dos inteiros entre eles
void swap(int* a, int* b);

/// Entrada: um vetor de char
/// Pré-condição: nenhuma
/// Pós-condição: lê da entrada de dados padrão um conjunto e o retona
char *readSet(char set[]);

/// Entrada: um vetor de char
/// Pré-condição: nenhuma
/// Pós-condição: printa na saida de dados padrão o vetor fornecido
void printSet(char subset[]);

/// Entrada: um inteiro num
/// Pré-condição: nenhuma
/// Pós-condição: lê da entrada padrão um inteiro e armazena em num
void readNum(int *num);

#endif // RECURSIVEFUNCTIONS_H
