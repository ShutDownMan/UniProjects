#include <stdio.h>


/*
	1) Criar uma função que verifica se um char é uma letra minúscula
	2) Criar uma função que verifica se um char é um número
	3) Criar uma função que verifica se um char é uma letra maiúscula
	4) Criar uma função que converte uma lera minuscula em maiúscula
	5) Criar uma função que verifica se um char é um operador
	6) Criar uma função que 

*/

char isMinusculo(char c) {
	return (c >= 'a' && c <= 'z') ? 1 : 0;
}

char isDigit(char c){
    return (c-'0' >= '0' && c-'0' <= '9');
}

char isMaiuculo(char c) {
	return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

char toUpper(char c) {
	return c - 32;
}

char isOperator(char c) {
	if()
}

int main(int argc, char const *argv[])
{
	
	return 0;
}