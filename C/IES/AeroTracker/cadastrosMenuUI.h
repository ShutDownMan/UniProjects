#ifndef CADASTROSMENUUI_H
#define CADASTROSMENUUI_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "cadastrosVooUI.h"

/*!
	@brief menuCadastros, menu de opções de cadastros
	@precondition nenhuma
	@postcondition nenhuma
*/
void menuCadastros();

/*!
	@brief escolhaCadastros, apresenta opções para o usuário e recolhe \
	sua escolha
	@return escolha feita pelo usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
char escolhaCadastros();

/*!
	@brief telaCadastros, apresenta tela de opções ao usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
void telaCadastros();

#endif // CADASTROSMENUUI_H