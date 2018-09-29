#include "start.h"
#include "..\ui\menus.h"

int main(int argc, char const *argv[]) {
	// TODO: initialize app database
	AppDatabase *db = NULL;

	setupConsole();

	mainMenu(db);

	return 0;
}