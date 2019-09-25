#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int delay;
char *command;


int main(int argc, char const *argv[]) {
	delay = 60;

	if(argc >= 2) command = argv[1];
	if(argc >= 3) delay = atoi(argv[2]);

	// printf("delay = %d\n", delay);

	while(1) {
		sleep(delay);

		// printf("command = %s\n", command);

		system(command);

	}

	return 0;
}

//  "pgrep -x dunst >/dev/null && notify-send \"This Month\" \"$(cal --color=always | sed \"s/..7m/<b><span color=\\"red\\">/;s/..27m/<\/span><\/b>/\")\" && notify-send \"Appointments\" \"$(calcurse -D ~/.config/calcurse -d3)\""
//  'pgrep -x dunst >/dev/null && notify-send "This Month" "$(cal --color=always | sed "s/..7m/<b><span color=\"red\">/;s/..27m/<\/span><\/b>/")" && notify-send "Appointments" "$(calcurse -D ~/.config/calcurse -d3)" '
// commandRepeater 'pgrep -x dunst >/dev/null && notify-send "This Month" "$(cal --color=always | sed "s/..7m/<b><span color=\"red\">/;s/..27m/<\/span><\/b>/")" && notify-send "Appointments" "$(calcurse -D ~/.config/calcurse -d3)" ' 15


