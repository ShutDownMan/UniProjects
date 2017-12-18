#include <stdio.h>
#include <stdlib.h>

#define MAXPTR 128
#define MAXSTR 128

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

	totalClientsNum = 0;
	totalAccountsNum = 0;


	totalClients = malloc(sizeof(Client*) * MAXPTR);
	totalAccounts = malloc(sizeof(Account*) * MAXPTR);

	if(!(load("clientes.txt", totalClients, &totalClientsNum, totalAccounts, &totalAccountsNum))) return 1;

	totalClients = realloc(totalClients, sizeof(Client*) * totalClientsNum);
	totalAccounts = realloc(totalAccounts, sizeof(Client*) * totalAccountsNum);

	// movimentos aqui



	return 0;
}

int load(char fileName[], Client** totalClients, int* totalClientsNum, Account** totalAccounts, int* totalAccountsNum) {
	int i;
	FILE* f;

	if(!(f = fopen(fileName, "r"))) return 1;

	for (i = 0; !feof(f); ++i) {
		totalClients[i] = malloc(sizeof(Client));
		totalClients[i]->name = malloc(sizeof(char) * MAXSTR);

		fscanf(f, "%[^\n]%*c", totalClients[i]->name);

		loadAccount(f, totalClients[i], totalAccounts, totalAccountsNum);

		printf("NAME: %s\n", totalClients[i]->name);
		printf("ACCOUNT: %d\n", totalClients[i]->accounts[0]->id);
		printf("Saldo %.2f\n", totalClients[i]->accounts[0]->balance);
		printf("----------------------\n");
	}
}

int loadAccount(FILE* f, Client* currClient, Account** totalAccounts, int* totalAccountsNum) {
	int i, id, digit, accountID;
	float accountBalance;
	Account* foundAccount = NULL;

	fscanf(f, "%d-%d%*c", &id, &digit);
	accountID = id*10 + digit;
	fscanf(f, "%f%*c", &accountBalance);

	if(currClient->accountsNum >= 10) return 1;

	foundAccount = findAccount(accountID, totalAccounts, *totalAccountsNum);

	printf("Accounts: %d\n", *totalAccountsNum);

	if(!foundAccount) {
		foundAccount = malloc(sizeof(Account));

		foundAccount->id = accountID;
		foundAccount->balance = accountBalance;

		totalAccounts[(*totalAccountsNum)++] = foundAccount;
	}

	if(foundAccount->clientsNum > 2) return 2;

	currClient->accounts[currClient->accountsNum++] = foundAccount;

	return 0;
}

Account* findAccount(int accountID, Account** totalAccounts, int totalAccountsNum) {
	int i;

	for (i = 0; i < totalAccountsNum; ++i) {
		if(totalAccounts[i]->id == accountID) {
			return totalAccounts[i];
		}
	}

	return NULL;
}