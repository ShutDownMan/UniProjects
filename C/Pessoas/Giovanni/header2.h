#ifndef HEADER2_H_INCLUDED
#define HEADER2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


struct transicoes{
	char estados[20];
	int comple;
};

char alfabeto[50],virgula;
int inicial, num_estados, num_finais, tam_palavra, finais[20], estados[27], numtrans[50],Etrans[15][15];
struct transicoes trans[50][50];



//Entrada: Palavra de entrada.
//Saida: Retorna essa palavra.
//Pre-condicao: Nenhuma.
//Pos-Condicao: Nenhuma.
//Descricao:Entra com uma palavra e limpa o teclado, nome do arquivo, cadeia para o AFD, etc.
void entra_palavra(char *palavra);




//Entrada: Nenhuma.
//Saida: Nenhuma.
//Pre-condicao: Nenhuma.
//Pos-Condicao: Nenhuma.
//Descricao:Limpa as variaveis do struct.
void limpa_str();




//Entrada: Nome do arquivo.
//Saida: Nenhuma.
//Pre-Condicao: Nome de arquivo com txt valido.
//Pos-Condicao: Arquivo e carregado na memoria.
//Descricao: A partir do nome do arquivo (char nome), o mesmo e aberto e assim carregado todos os dados do AFD.
void carrega_arquivo(char *nome);




//Entrada: Palavra de entrada.
//Saida: Retorna 1 se a palavra nao pertence ao alfabeto e 0 caso pertenca.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Teste da Palavra.
//Descricao: A partir da entrada de uma palavra (char palavra), a mesma e testada com o alfabeto carregado do arquivo.
int testa_palavra(char *palavra);





//Entrada: Palavra de entrada.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo Carregado e Palavra Valida.
//Pos-Condicao: Mostrar na tela o processamento da palavra.
//Descricao: Avalia as transicoes do automoto carregado, mostrando se for valida ou nao.
void processa_palavra(char *palavra);





//Entrada: Nenhuma.
//Saida: Nenhuma.
//Pre-Condicao: Nenhuma.
//Pos-Condicao: Nenhuma.
//Descricao: Faz a impressao do menu e a chamada das funcoes anteriores.
void menu();


void limpa_Etrans(int mat[][15]);

#endif // HEADER2_H_INCLUDED
