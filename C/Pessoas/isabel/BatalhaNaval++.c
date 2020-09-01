#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct jogador
{
	char nome[8];
	unsigned int jogadas;
	unsigned int jogadasMax;
} Jogador;

typedef struct celula
{
	char tipo;
} Celula;

// tipos:
// -2 - marcado
// -1 - desconhecido
//  0 - agua
//  1 - submarino
//  2 - barco
//  3 - navio
//  4 - fragata
//  5 - porta-avioes

typedef struct tabuleiro
{
	Celula celulasRespostaMat[16][16];
	Celula celulasMat[16][16];
	int largura, altura;
	int pecas;
} Tabuleiro;

void telaInicial();

void lerNomeJogador(Jogador *jogador);

void inicializarTabuleiro(Tabuleiro *tabuleiro);

void colocaEmbarcacao(Tabuleiro *tabuleiro, int linha1, int coluna1, int linha2, int coluna2, int tipo);

void printRespostaTabuleiro(Tabuleiro *tabuleiro);

void printTabuleiro(Tabuleiro *tabuleiro);

void clearStdin();

void fazJogada(Jogador *jogador, Tabuleiro *tabuleiro, char jogada[]);

void mostrarAjuda();

char getAtirar();

void atirarTabuleiro(Tabuleiro *tabuleiro, int linhaInd, int colunaInd);

void marcarTabuleiro(Tabuleiro *tabuleiro, int linhaInd, int colunaInd);

char isFim(Jogador *jogador, Tabuleiro *tabuleiro);

void printaFim(Jogador *jogador, Tabuleiro *tabuleiro);

int main(void)
{
	Jogador jogador;
	Tabuleiro tabuleiro;
	char entradaStr[8];

	/// locale para português por causa dos acentos
	setlocale(LC_ALL, "Portuguese");

	/// printa apresentação do jogo
	telaInicial();

	/// lê nome do jogador
	lerNomeJogador(&jogador);

	/// inicializa jogador
	jogador.jogadas = 0;
	jogador.jogadasMax = 16;

	/// inicializa tabuleiro
	inicializarTabuleiro(&tabuleiro);

	// printRespostaTabuleiro(&tabuleiro);

	/// loop principal do jogo
	do
	{
		/// printa o tabuleiro atual
		printTabuleiro(&tabuleiro);
		puts("------------------------");

		/// lê jogada atual
		printf("você ainda tem %d jogada(s)\n", jogador.jogadasMax - jogador.jogadas);
		puts("digite sua jogada (? - ajuda):");
		fgets(entradaStr, 8, stdin);

		/// repete enquanto entrada for vazia
		while (entradaStr[0] == '\n')
		{
			puts("entrada inválida!");
			puts("digite sua jogada novamente (? - ajuda): ");
			fgets(entradaStr, 8, stdin);
		}

		/// realiza jogada de acordo com a entrada
		fazJogada(&jogador, &tabuleiro, entradaStr);

	} while (!isFim(&jogador, &tabuleiro));

	printaFim(&jogador, &tabuleiro);

	return 0;
}

void telaInicial()
{
	puts("Bem vindo a BatalhaNaval++");
	puts("");

	puts("Aperte Enter para continuar...");

	getchar();
}

void lerNomeJogador(Jogador *jogador)
{
	/// lê entrada
	puts("Por favor digite seu nome:");
	fgets(jogador->nome, 8, stdin);

	/// enquanto for vazia
	while (jogador->nome[0] == '\n')
	{
		puts("Nome inválido!");
		puts("Por favor, digite seu nome novamente:");
		fgets(jogador->nome, 8, stdin);
	}

	/// fecha string para evitar problemas
	jogador->nome[strlen(jogador->nome) - 1] = '\0';

	putc('\n', stdout);

	printf("Olá %s, se prepare que o jogo já irá começar.\n", jogador->nome);
}

void inicializarTabuleiro(Tabuleiro *tabuleiro)
{
	int i, j;
	tabuleiro->largura = 8;
	tabuleiro->altura = 8;
	tabuleiro->pecas = 0;

	puts("Inicializando tabuleiro...\n");

	/// para cada celula
	for (i = 0; i < tabuleiro->altura; ++i)
	{
		for (j = 0; j < tabuleiro->largura; ++j)
		{
			/// inicializa valores
			tabuleiro->celulasMat[i][j].tipo = -1;
			tabuleiro->celulasRespostaMat[i][j].tipo = 0;
		}
	}

	/// coloca embarcações no tabuleiro
	colocaEmbarcacao(tabuleiro, 2, 2, 2, 2, 1);
	colocaEmbarcacao(tabuleiro, 7, 6, 7, 6, 1);
	colocaEmbarcacao(tabuleiro, 0, 0, 0, 1, 2);
	colocaEmbarcacao(tabuleiro, 4, 1, 6, 1, 3);
	colocaEmbarcacao(tabuleiro, 1, 4, 1, 7, 3);
	colocaEmbarcacao(tabuleiro, 5, 3, 5, 6, 4);
	colocaEmbarcacao(tabuleiro, 3, 3, 3, 8, 5);
}

void colocaEmbarcacao(Tabuleiro *tabuleiro, int linha1, int coluna1, int linha2, int coluna2, int tipo)
{
	int i, j;

	/// para cada linha e coluna
	for (i = linha1; i <= linha2; ++i)
	{
		for (j = coluna1; j <= coluna2; ++j)
		{
			if (tabuleiro->celulasRespostaMat[i][j].tipo == 0)
			{
				/// aumenta o número de peças no tabuleiro
				tabuleiro->pecas++;
			}
			/// preenche com a embarcação indicada
			tabuleiro->celulasRespostaMat[i][j].tipo = tipo;
		}
	}
}

void printRespostaTabuleiro(Tabuleiro *tabuleiro)
{
	int i, j;
	char codesMais[7] = "~sbnfp";
	char codesMenos[7] = "#0";

	/// para cada celula
	for (i = -1; i < tabuleiro->altura; ++i)
	{
		for (j = -1; j < tabuleiro->largura; ++j)
		{
			if (i < 0 && j < 0)
				continue;
			/// printa nomes das colunas
			if (i < 0)
			{
				printf(" %2d", j + 1);
				continue;
			}
			/// printa nomes das linhas
			else if (j < 0)
			{
				printf("%c ", 'A' + i);
				continue;
			}

			/// printa simbolo de acordo com o tipo da celula
			if (tabuleiro->celulasRespostaMat[i][j].tipo < 0)
			{
				putc(codesMenos[-tabuleiro->celulasRespostaMat[i][j].tipo - 1], stdout);
			}
			else
			{
				putc(codesMais[tabuleiro->celulasRespostaMat[i][j].tipo], stdout);
			}

			printf("  ");
		}
		putc('\n', stdout);
	}
}

void printTabuleiro(Tabuleiro *tabuleiro)
{
	int i, j;
	char codesMais[7] = "~sbnfp";
	char codesMenos[7] = "#0";

	/// para cada celula
	for (i = -1; i < tabuleiro->altura; ++i)
	{
		for (j = -1; j < tabuleiro->largura; ++j)
		{
			if (i < 0 && j < 0)
				continue;
			/// printa nomes das colunas
			if (i < 0)
			{
				printf(" %2d", j + 1);
				continue;
			}
			/// printa nomes das linhas
			else if (j < 0)
			{
				printf("%c ", 'A' + i);
				continue;
			}

			/// printa simbolo de acordo com o tipo da celula
			if (tabuleiro->celulasMat[i][j].tipo < 0)
			{
				putc(codesMenos[-tabuleiro->celulasMat[i][j].tipo - 1], stdout);
			}
			else
			{
				putc(codesMais[tabuleiro->celulasMat[i][j].tipo], stdout);
			}
			printf("  ");
		}
		putc('\n', stdout);
	}
}

void clearStdin()
{
	/// limpa entrada
	while ((getchar()) != '\n')
		;
}

void fazJogada(Jogador *jogador, Tabuleiro *tabuleiro, char jogada[])
{
	char isInvalida = 0, *endptr, atirar;
	int linhaIndex = -1, colunaIndex = -1;

	/// se entrada for ajuda
	if (jogada[0] == '?')
	{
		mostrarAjuda();
		return;
	}

	/// se os dois primeiros chars forem letra ou numero
	if (isalnum(jogada[0]) && isalnum(jogada[1]))
	{
		/// se o primeiro char é letra
		if (!isdigit(jogada[0]))
		{
			/// conta para o indice da linha
			linhaIndex = toupper(jogada[0]) - 'A';
		}
		else
		{
			// putc('!', stdout);
			/// não é letra é invalido
			isInvalida = 1;
		}
		if (isdigit(jogada[1]))
		{
			colunaIndex = strtol(jogada + 1, &endptr, 10);
		}
		else
		{
			// putc('!', stdout);
			/// se não é número é invalido
			isInvalida = 1;
		}
	}

	/// se o indice calculado não está dentro da matriz
	if (linhaIndex < 0 || linhaIndex >= tabuleiro->altura ||
		colunaIndex <= 0 || colunaIndex >= tabuleiro->largura)
	{
		// putc('!', stdout);
		isInvalida = 1;
	}
	colunaIndex--;

	/// se é invalido avisa jogador e retorna
	if (isInvalida)
	{
		puts("jogada inválida!");
		getchar();
		return;
	}

	/// se o valor da celula selecionado já é conhecido
	if (tabuleiro->celulasMat[linhaIndex][colunaIndex].tipo >= 0)
	{
		puts("Celula selecionada já revelada!");
		getchar();
		return;
	}

	// printf("%d - %d\n", linhaIndex, colunaIndex);

	/// pergunta para o jogador se deseja atirar na posicao
	/// ou apenas marcar
	atirar = getAtirar();

	/// se deseja atirar
	if (atirar)
	{
		/// revela posição
		atirarTabuleiro(tabuleiro, linhaIndex, colunaIndex);
		/// incrementa jogada
		jogador->jogadas++;
	}
	else
	{
		/// marca no tabuleiro a posição
		marcarTabuleiro(tabuleiro, linhaIndex, colunaIndex);
	}
}

void mostrarAjuda()
{
	puts("------------------------");
	puts("Para fazer uma jogada");
	puts("digite uma letra referente a linha");
	puts("e um número referente a coluna");
	puts("que deseja selecionar");
	putchar('\n');

	puts("Exemplo:");
	puts("C4");
	putchar('\n');

	puts("Depois indique se deseja marcar ou atirar");
	puts("digitando M ou A");
	putchar('\n');

	puts("Aperte Enter para continuar...");

	getchar();
	clearStdin();
}

char getAtirar()
{
	char entradaStr[2];

	/// lê entrada
	puts("Deseja (M)arcar ou (A)tirar na célula selecionada?");
	fgets(entradaStr, 2, stdin);
	entradaStr[0] = toupper(entradaStr[0]);
	/// enquanto entrada for invalida
	while (entradaStr[0] != 'M' && entradaStr[0] != 'A')
	{
		puts("entrada inválida!");
		puts("Deseja (M)arcar ou (A)tirar na célula selecionada?");
		fgets(entradaStr, 2, stdin);
		entradaStr[0] = toupper(entradaStr[0]);
	}

	/// limpa entrada e retorna escolha
	clearStdin();
	return (entradaStr[0] == 'A');
}

void atirarTabuleiro(Tabuleiro *tabuleiro, int linhaInd, int colunaInd)
{
	/// se celula atual é uma embarcação
	if (tabuleiro->celulasRespostaMat[linhaInd][colunaInd].tipo > 0)
	{
		tabuleiro->pecas--;
	}
	tabuleiro->celulasMat[linhaInd][colunaInd].tipo = tabuleiro->celulasRespostaMat[linhaInd][colunaInd].tipo;
}

void marcarTabuleiro(Tabuleiro *tabuleiro, int linhaInd, int colunaInd)
{
	/// marca no tabuleiro a posição
	tabuleiro->celulasMat[linhaInd][colunaInd].tipo = -2;
}

char isFim(Jogador *jogador, Tabuleiro *tabuleiro)
{
	/// retorna se jogador está sem jogadas ou se não existem mais peças no tabuleiro
	return (jogador->jogadas > jogador->jogadasMax || !tabuleiro->pecas);
}

void printaFim(Jogador *jogador, Tabuleiro *tabuleiro)
{
	puts("Fim de jogo!");

	/// se tabuleiro está sem peças
	if (!tabuleiro->pecas)
	{
		/// jogador venceu
		puts("vitória !!! =D");
		printf("Parabéns %s, você ganhou o jogo!\n", jogador->nome);
	}
	else if (jogador->jogadas >= jogador->jogadasMax)
	{
		/// senão, ele perdeu
		puts("derrota :(");
		printf("%s, infelizmente você não tem mais jogadas.\n", jogador->nome);
	}

	/// mostra tabuleiro resposta
	printRespostaTabuleiro(tabuleiro);

	puts("Aperte Enter para continuar...");
	getchar();
}