#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

	int i;
	int indice = 0;
	int l_minuscula = 0;
	int l_maiuscula = 0;
	int dig_num = 0;
	int carac_esp = 0;
	char str[1024];

	while(scanf("%[^\n]%*c", str) != EOF){
		if((strlen(str) >= 6) && (strlen(str) <= 32)) indice ++;

		for(i = 0; str[i]; i++){
			if(islower(str[i])){
				l_minuscula ++;
			}else
				if(isupper(str[i])){
					l_maiuscula ++;
				}else
					if(isdigit(str[i])){
						dig_num ++;
					}else
						if(!isalnum(str[i])){
							carac_esp ++;
					}
		}

		if(l_minuscula) indice ++;
		if(l_maiuscula) indice ++;
		if(dig_num) indice ++;
		if(carac_esp) indice = 0;

		if(indice == 4) printf("Senha Valida\n");
		else printf("Senha Invalida\n");

		l_minuscula = 0;
		l_minuscula = 0;
		dig_num = 0;
		carac_esp = 0;
		indice = 0;
	}

	return 0;

}