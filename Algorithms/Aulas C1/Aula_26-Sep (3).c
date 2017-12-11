#include <stdio.h>
#include <string.h>

#define MAX 100

int getseq(char str[]) {
	int i, mseq, curseq;

	curseq = curseq = 1;
	for (i = 0; str[i]; ++i) {
		if(str[i]+1 == str[i+1]) {
			curseq++;
		} else if(curseq > mseq) {
			mseq = curseq;
			curseq = 1;
		}
	}

	return mseq;
}

int main(int argc, char const *argv[]) {
	char str[MAX];

	gets(str);
	while(strcmp(str, "exit")) {
		printf("%d\n", getseq(str));

		gets(str);
	}

	return 0;
}