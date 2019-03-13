#ifndef VOOINFO_H
#define VOOINFO_H

#include <stdlib.h>

#define MAX_PREFIXO_LENGTH 16
#define MAX_AEROPORTO_NAME_LENGTH 64
#define MAX_AEROPORTO_SIGLA_LENGTH 4
#define MAX_MODELO_AERONAVE 64

typedef struct Hora {
	char hh, mm;
} Hora;

typedef struct VooInfo {
	char prefixo[MAX_PREFIXO_LENGTH];
	char origem[MAX_AEROPORTO_NAME_LENGTH], destino[MAX_AEROPORTO_NAME_LENGTH];
	char origemSigla[MAX_AEROPORTO_SIGLA_LENGTH], destinoSigla[MAX_AEROPORTO_SIGLA_LENGTH];
	Hora partida, chegada, duracao;
	char modeloAeronave[MAX_MODELO_AERONAVE];
} VooInfo;

VooInfo *createVooInfo();

#endif // VOOINFO_H