#include <stdio.h>
#include <stdlib.h>

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
		// aloca memória tamanho Account para indice i da matriz totalAccounts
		totalClients[i]->name = malloc(sizeof(char) * MAXSTR);

		// inicializa numero de contas para 1
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