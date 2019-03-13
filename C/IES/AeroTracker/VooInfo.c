#include "VooInfo.h"

VooInfo *createVooInfo() {
	VooInfo *novoVooInfo = (VooInfo*)malloc(sizeof(VooInfo));

	novoVooInfo->prefixo[0] = '\0';
	novoVooInfo->origem[0] = '\0';
	novoVooInfo->destino[0] = '\0';

	novoVooInfo->partida.hh = -1;
	novoVooInfo->partida.mm = -1;
	novoVooInfo->chegada.hh = -1;
	novoVooInfo->chegada.mm = -1;
	novoVooInfo->duracao.hh = -1;
	novoVooInfo->duracao.mm = -1;

	novoVooInfo->modeloAeronave[0] = '\0';

	return novoVooInfo;
}