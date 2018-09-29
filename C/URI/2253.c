#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	int i;
	char pass[1024];
	char haveLowerCase, haveUpperCase, haveNumber;

	/// scaneia linha por linha enquanto
	while(!feof(stdin)) {
		/// lê uma linha inteira e armazena em pass
		scanf("%[^\n]%*c", pass);

		/// inicializa flags de aceitação da senha
		haveLowerCase = haveUpperCase = haveNumber = FALSE;

		/// para cada caractere em pass até chegar no '\0'
		for (i = 0; pass[i]; ++i) {

			/// se caractére atual é uma letra minuscula
			if(pass[i] >= 'a' && pass[i] <= 'z') {
				/// atribui valor para a flag de letra minuscula para TRUE (1)
				haveLowerCase = TRUE;
			} else if(pass[i] >= 'A' && pass[i] <= 'Z') { //< se caractére atual é uma letra maiuscula
				/// atribui valor para a flag de letra maiuscula para TRUE (1)
				haveUpperCase = TRUE;
			} else if(pass[i] >= '0' && pass[i] <= '9') { //< se caractére atual é um número
				/// atribui valor para a flag de número para TRUE (1)
				haveNumber = TRUE;
			} else { //< se não entrou em nenhum dos ifs anteriores, senha é invalida
				/// atribui valor de todas as flags para FALSE (0)
				haveLowerCase = haveUpperCase = haveNumber = FALSE;
			}
		}

		/// se senha satisfez todas as flags
		if(haveLowerCase && haveUpperCase && haveNumber) {
			/// se tamanho da senha é válido
			if(i >= 6 && i <= 32) {
				printf("Senha valida.\n");
			} else { //< senão
				printf("Senha invalida.\n");
			}
		} else { //< senão
			printf("Senha invalida.\n");
		}
	}

	return 0;
}