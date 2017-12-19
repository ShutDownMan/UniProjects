#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPTR 256
#define MAXSTR 256

typedef struct Client Client;
typedef struct Account Account;

typedef struct Client {
	char* name;
	Account* accounts[10];
	int accountsNum;
} Client;

typedef struct Account {
	int id;
	float balance;
	Client* clients[2];
	int clientsNum;
} Account;

int load(char fileName[], Client** totalClients, int* totalClientsNum, Account** totalAccounts, int* totalAccountsNum);
int loadAccount(FILE* f, Client* currClient, Account** totalAccounts, int* totalAccountsNum);

Account* findAccount(int accountID, Account** totalAccounts, int totalAccountsNum);

int movement(char fileName[], Client** totalClients, int totalClientsNum, Account** totalAccounts, int totalAccountsNum);
int draft(Account* originAccount, float quant);
int deposit(Account* originAccount, float quant);
int transfer(Account* originAccount, Account* destAccount, float quant);


int main(int argc, char const *argv[]) {
	Client** totalClients;
	Account** totalAccounts;
	int totalClientsNum, totalAccountsNum;

	// Inicializa contadores de clientes e contas em 0 (importante)
	totalClientsNum = 0;
	totalAccountsNum = 0;

	// aloca MAXPTR de memória para ambos vetores
	totalClients = malloc(sizeof(Client*) * MAXPTR);
	totalAccounts = malloc(sizeof(Account*) * MAXPTR);

	// carrega do arquivo os clientes
	if(!(load("clientes.txt", totalClients, &totalClientsNum, totalAccounts, &totalAccountsNum))) return 1;

	// realoca memória para tamanho descoberto dos vetores
	totalClients = realloc(totalClients, sizeof(Client*) * totalClientsNum);
	totalAccounts = realloc(totalAccounts, sizeof(Account*) * totalAccountsNum);

	// movimentos aqui

	movement("movimentos.txt", totalClients, totalClientsNum, totalAccounts, totalAccountsNum);

	return 0;
}

int load(char fileName[], Client** totalClients, int* totalClientsNum, Account** totalAccounts, int* totalAccountsNum) {
	int i;
	FILE* f;

	// abre arquivo de entrada
	if(!(f = fopen(fileName, "r"))) return 1;

	// ler arquivo até fim deste
	for (i = 0; !feof(f); ++i) {
		// aloca memória tamanho Cliente para indice i da matriz totalClients
		totalClients[i] = malloc(sizeof(Client));
		// aloca memória tamanho MAXSTR para nome do dono da conta
		totalClients[i]->name = malloc(sizeof(char) * MAXSTR);

		// inicializa numero de contas para 0
		totalClients[i]->accountsNum = 0;

		// lê nome do dono da conta
		fscanf(f, "%[^\n]%*c", totalClients[i]->name);

		// carrega conta para struct Cliente
		loadAccount(f, totalClients[i], totalAccounts, totalAccountsNum);

		// Debug
		printf("NAME: %s\n", totalClients[i]->name);
		printf("ACCOUNT: %d\n", totalClients[i]->accounts[0]->id);
		printf("SALDO: %.2f\n", totalClients[i]->accounts[0]->balance);
		printf("----------------------\n");
	}
}

int loadAccount(FILE* f, Client* currClient, Account** totalAccounts, int* totalAccountsNum) {
	int i, id, digit, accountID;
	float accountBalance;
	Account* foundAccount = NULL;

	// lè id da conta
	fscanf(f, "%d-%d%*c", &id, &digit);
	// calcula id para int
	accountID = id*10 + digit;
	// lê saldo da conta
	fscanf(f, "%f%*c", &accountBalance);

	// se cliente não tem mais de 10 contas
	if(currClient->accountsNum >= 10) return 1;

	// tenta achar conta na lista de contas
	foundAccount = findAccount(accountID, totalAccounts, *totalAccountsNum);

	printf("Accounts: %d\n", *totalAccountsNum);

	// se não achou, cria uma e coloca na lista
	if(!foundAccount) {
		foundAccount = malloc(sizeof(Account));

		foundAccount->id = accountID;
		foundAccount->balance = accountBalance;
		foundAccount->clientsNum = 1;

		totalAccounts[(*totalAccountsNum)++] = foundAccount;
	}

	// se a conta nn tem mais de 2 donos
	if(foundAccount->clientsNum > 2) return 2;

	// adiciona a lista de contas do cliente
	currClient->accounts[currClient->accountsNum++] = foundAccount;

	return 0;
}

Account* findAccount(int accountID, Account** totalAccounts, int totalAccountsNum) {
	int i;

	// para cada conta em totalAccounts
	for (i = 0; i < totalAccountsNum; ++i) {
		// se o id se iguala
		if(totalAccounts[i]->id == accountID) {
			// retorna conta atual
			return totalAccounts[i];
		}
	}

	return NULL;
}

int movement(char fileName[], Client** totalClients, int totalClientsNum, Account** totalAccounts, int totalAccountsNum) {
	FILE* f;
	int i, originAccountID, destAccountID, transactionState;
	int dia, mes, ano;
	float quant;
	char type[MAXSTR];

	// abre arquivo de movimentos
	if(!(f = fopen(fileName, "r"))) return 1;

	// inicializa variáveis para 0 (importante)
	originAccountID = 0;
	destAccountID = 0;

	// enquanto não fim de arquivo
	for (i = 0; !feof(f); ++i) {
		transactionState = 0;
		// ler tipo de transação
		fscanf(f, "%s", type);
		// ler data
		fscanf(f, "%d/%d/%d", &dia, &mes, &ano);

		printf("%d : %s\n", i, type);

		// se transação for saque
		if(!strcmp(type, "SAQUE")) {
			// ler parametroz para saque
			fscanf(f, "%d %f", &originAccountID, &quant);
			// tentar realizar saque
			transactionState = draft(findAccount(originAccountID, totalAccounts, totalAccountsNum), quant);

			// se deu certo
			if(!transactionState) {
				// mensagem de sucesso
				printf("%d/%d/%d\n", dia, mes, ano);
				printf("Transação tipo 'SAQUE' realizada com sucesso na conta: %d\n", originAccountID);
			}
		}

		// se transação for depósito
		if(!strcmp(type, "DEPOSITO")) {
			// ler parametros para deposito
			fscanf(f, "%d %f", &originAccountID, &quant);

			// tentar realizar saque
			transactionState = deposit(findAccount(originAccountID, totalAccounts, totalAccountsNum), quant);

			// se deu certo
			if(!transactionState) {
				// mensagem de sucesso
				printf("%d/%d/%d\n", dia, mes, ano);
				printf("Transação tipo 'DEPOSITO' realizada com sucesso na conta: %d\n", originAccountID);
			}
		}

		// se transação for transferência
		if(!strcmp(type, "TRANSFERE")) {
			// ler parâmetros para transferência
			fscanf(f, "%d %d %f", &originAccountID, &destAccountID, &quant);

			// tentar realizar transferência
			transactionState = transfer(findAccount(originAccountID, totalAccounts, totalAccountsNum), findAccount(destAccountID, totalAccounts, totalAccountsNum), quant);

			// se deu certo
			if(!transactionState) {
				// mensagem de sucesso
				printf("%d/%d/%d\n", dia, mes, ano);
				printf("Transação tipo 'TRANSFERE' realizada com sucesso nas contas: %d => %d\n", originAccountID, destAccountID);
			}
		}

		//fscanf(f, "%*c");

		// mensagens de erro
		switch(transactionState) {
			case 0:
				break;

			case 1:
				printf("Conta inexistente.\n");
				break;

			case 2:
				printf("Saldo insuficuente para realizar transação.\n");
				break;

			case 3:
				break;

			default:
				printf("Algum erro no processo de transação\n");
				break;
		}
		printf("------------\n");
	}
}

int draft(Account* originAccount, float quant) {
	if(!originAccount) return 1;
	if(originAccount->balance < quant) return 2;

	printf("NAME: %s\n", originAccount->clients[0]->name);

	originAccount->balance -= quant;

	return 0;
}

int deposit(Account* originAccount, float quant) {
	if(!originAccount) return 1;

	originAccount->balance += quant;

	return 0;
}

int transfer(Account* originAccount, Account* destAccount, float quant) {
	if(!originAccount || !destAccount) return 1;

	draft(originAccount, quant);
	deposit(destAccount, quant);

	return 0;
}