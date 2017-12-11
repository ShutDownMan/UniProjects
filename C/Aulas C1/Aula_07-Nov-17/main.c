#include <stdio.h>
#include <stdlib.h>

#define MAX 256

typedef struct {
	int dia, mes, ano;
} Data;

typedef struct {
	char nome[MAX];
	char sexo;

	float peso, altura, imc;

	Data nasc;

} Pessoa;

void read(FILE* f, Pessoa* p) {

	fscanf(f, "%[^\n]%*c", p->nome);
	fscanf(f, "%f %f%*c", &p->peso, &p->altura);
	fscanf(f, "%c%*c", &p->sexo);
	fscanf(f, "%d %d %d%*c", &(p->nasc.dia), &(p->nasc.mes), &(p->nasc.ano));

}

int loaddados(char filename[], Pessoa pessoas[], int* length) {
	FILE* dados;
	int i;

	if(!(dados = fopen("dados.txt", "r"))) return 0;

	for (i = 0; !feof(dados); ++i) {
		read(dados, &pessoas[i]);

		//fprintf(stderr, "pessoas[%d] = %s / %g / %g\n", i, pessoas[i].nome, pessoas[i].peso, pessoas[i].altura);
	}

	*length = i;

	return 0;
}

void write(FILE* f, Pessoa const p) {


	fprintf(f, "%s (%c):\n", p.nome, p.sexo);
	fprintf(f, "\tNasceu em %d/%d/%d\n", p.nasc.dia, p.nasc.mes, p.nasc.ano);
	fprintf(f, "\tpeso = %g\n", p.peso);
	fprintf(f, "\taltura = %g\n", p.altura);
	fprintf(f, "\timc = %g\n", p.imc);

}

int relat(char filename[], Pessoa pessoas[], int length) {
	FILE* relat;
	int i;

	if(!(relat = fopen("relat.txt", "w"))) return 1;

	for (i = 0; i < length; ++i) {
		write(relat, pessoas[i]);
	}

	return 0;
}

void calc(Pessoa pessoas[], int length) {
	int i;

	for (i = 0; i < length; ++i) {
		pessoas[i].imc = pessoas[i].peso / (pessoas[i].altura*pessoas[i].altura);
	}
}

int datatonum(Data d) {
	return 10000*d.ano + 100*d.mes + d.dia;
}

Pessoa older(Pessoa pessoas[], int length) {
	int i;
	Pessoa oldest = pessoas[0];

	for (i = 1; i < length; ++i) {
		if(datatonum(pessoas[i].nasc) < datatonum(oldest.nasc)) {
			oldest = pessoas[i];
		}
	}

	return oldest;
}

Pessoa hiimcporsexo(Pessoa pessoas[], int length, char sexo) {
	int i;
	Pessoa pessoahiimc;

	for (i = 0; i < length; ++i) {
		if(pessoas[i].imc > pessoahiimc.imc) {
			if(pessoas[i].sexo == sexo) {
				pessoahiimc = pessoas[i];
			}
		}
	}

	return pessoahiimc;
}

Pessoa gethighestimc(Pessoa pessoas[], int length) {
	int i;
	Pessoa pessoahiimc = pessoas[0];

	for (i = 1; i < length; ++i) {
		if(pessoas[i].imc > pessoahiimc.imc) {
			pessoahiimc = pessoas[i];
		}
	}

	return pessoahiimc;
}

int main(int argc, char const *argv[]) {
	Pessoa pessoas[MAX];
	int length;

	if(!(loaddados("dados.txt", pessoas, &length))) {
		calc(pessoas, length);
		relat("relat.txt", pessoas, length);

		write(stdout, older(pessoas, length));

		write(stdout, hiimcporsexo(pessoas, length, 'F'));
		write(stdout, gethighestimc(pessoas, length));

	} else {
		fprintf(stderr, "ERRO! - (main)\n");
	}


	return 0;
}