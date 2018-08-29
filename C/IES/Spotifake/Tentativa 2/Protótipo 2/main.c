#include "start.h"
#include "menus.h"

int main(int argc, char const *argv[]) {
	// TODO: initialize app database
	AppDatabase *db;

	setupConsole();

	mainMenu(db);

	return 0;
}