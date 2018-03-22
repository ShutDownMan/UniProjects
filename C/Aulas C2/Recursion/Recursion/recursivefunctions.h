#ifndef RECURSIVEFUNCTIONS_H
#define RECURSIVEFUNCTIONS_H

/// Entrada: um inteiro n
/// Pré-condições: nenhuma
/// Pós-condições: Retorna o fatorial de n
long long int fac(int n);

/// Entrada: um inteiro n
/// Pré-condições: nenhuma
/// Pós-condições: retorna o nésimo número da seq. fibonacci
long long int fib(int n);

/// Entrada: um inteiro n
/// Pré-condições: nenhuma
/// Pós-condições: retorna o inverso de n
int rev(int n);

/// Entrada: um vetor de inteiros e um inteiro length
/// Pré-condições: nenhuma
/// Pós-condições: retorna a soma dos valores no vetor
int vetSum(int length, int vet[]);

/// Entrada: um inteiro n
/// Pré-condições: nenhuma
/// Pós-condições: retorna a soma de todos os numeros até n
int sumFromN(int n);

/// Entrada: dois inteiros, k e n
/// Pré-condições: nenhuma
/// Pós-condições: retorna k elevado a n
int kPowN(int k, int n);

/// Entrada: um vetor de inteiros e um inteiro length
/// Pré-condições: nenhuma
/// Pós-condições: inverte a ordem dos valores no vetor
void invertVet(int length, int vet[]);

/// Entrada: dois inteiros, k e n
/// Pré-condições: nenhuma
/// Pós-condições: retorna o maior divisor comum entre k e n
int gdc(int n, int k);

/// Entrada: dois inteiros, k e n
/// Pré-condições: nenhuma
/// Pós-condições: retorna a qnt de ocorrencias de k em n
int occ(int k, int n);

/// Entrada: dois inteiros, k e n
/// Pré-condições: nenhuma
/// Pós-condições: multiplica n por k
int mult(int k, int n);

// HELPER FUNCTIONS //

/// Entrada: um vetor de inteiros e um inteiro length
/// Pré-condições: nenhuma
/// Pós-condições: lê vetor na entrada padrão
void readVet(int* length, int vet[]);

/// Entrada: um vetor de inteiros e um inteiro length
/// Pré-condições: nenhuma
/// Pós-condições: printa vetor na saida padrão
void printVet(int length, int vet[]);

/// Entrada: dois inteiros, a e b
/// Pré-condições: nenhuma
/// Pós-condições: troca os valores entre os inteiros
void swap(int *a, int *b);

#endif // RECURSIVEFUNCTIONS_H
