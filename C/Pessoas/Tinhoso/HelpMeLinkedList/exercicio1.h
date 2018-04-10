#ifndef EXERCICIO1_H
#define EXERCICIO1_H

// estrutura de n ́o para lista encadeada
typedef struct no {
int info;
struct no *prox;
} Lista;

// Testa se uma lista  ́e vazia
// Entrada: lista
// Retorno: 1 se a lista  ́e vazia ou 0 caso contr ́ario
// Pré-condi ̧c~ao: nenhuma
// Pós-condi ̧c~ao: nenhuma
int vazia(Lista * l);

// Insere um elemento na lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista alterada
// Pré-condi ̧c~ao: nenhuma
// Pós-condi ̧c~ao: elemento  ́e inserido na lista
Lista* insere(Lista* l, int info);

// Remove um elemento da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista alterada
// Pré-condi ̧c~ao: nenhuma
// Pós-condi ̧c~ao: elemento  ́e removido da lista
Lista* remover(Lista* l, int info);

// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condi ̧c~ao: nenhuma
// Pós-condi ̧c~ao: os elementos s~ao impressos no console
void imprime(Lista* l);

// Inverte uma lista
// Entrada: lista
// Retorno: lista invertida
// Pré-condi ̧c~ao: nenhuma
// Pós-condi ̧c~ao: lista original n~ao  ́e modificada
Lista* inverte(Lista* l);

// Concatena duas listas
// Entrada: listas a serem concatenadas
// Retorno: lista resultante da concatena ̧c~ao
// Pré-condi ̧c~ao: nenhuma
// Pós-condi ̧c~ao: listas originais n~ao s~ao modificadas
Lista* concatena(Lista* l1, Lista* l2);

// Intercala duas listas
// Entrada: listas a serem intercaladas
// Retorno: lista resultante da intercala ̧c~ao
// Pré-condi ̧c~ao: nenhuma
// Pós-condi ̧c~ao: listas originais permanecem inalteradas
Lista* merge(Lista* l1, Lista* l2);

Lista *eresni(Lista *l, int info);

Lista *criano(int val);

Lista *copiano(Lista *no);


#endif // EXERCICIO1_H
