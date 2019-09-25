#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h> 
#include <unistd.h>
#include <time.h>

#define MAX_FILE_NUM 255
#define MAX_STR 255

char *wallpaperFileNames[MAX_FILE_NUM];
int fileNum;
char *wallpaperDirectory = ".";
int delay;

const char *getFileNameExt(const char *fileName);

void shuffleWallpapers();

int main(int argc, char const *argv[]) {
	DIR *d;
	struct dirent *dir;

	srand(time(NULL));

	wallpaperDirectory = ".";
	delay = 160;
	
	if(argc >= 2) wallpaperDirectory = argv[1];
	if(argc >= 3) delay = argv[2];

	while (1) {
		fileNum = 0;
		d = opendir(wallpaperDirectory);
		
		if (d) {
			while ((dir = readdir(d)) && fileNum <= MAX_FILE_NUM) {
				// printf("ext = %s\n", getFileNameExt(dir->d_name));
				if(!strcmp(getFileNameExt(dir->d_name), "png")
					|| !strcmp(getFileNameExt(dir->d_name), "jpg")) {
					// printf("%s\n", dir->d_name);
					wallpaperFileNames[fileNum++] = dir->d_name;
				}
			}
			closedir(d);
		}
		
		if(fileNum) {
			char aux[MAX_STR];
			shuffleWallpapers();

			for (int i = 0; i < fileNum; ++i) {
				sleep(delay);

				// printf("FILE NAME = %s\n", wallpaperFileNames[i]);
				strcpy(aux, "setbg ");
				strcat(aux, wallpaperDirectory);
				strcat(aux, "/");
				strcat(aux, wallpaperFileNames[i]);
				// printf("COMMAND = %s\n", aux);

				system(aux);

			}
		}
	}

	return 0;
}

const char *getFileNameExt(const char *fileName) {
    const char *dot = strrchr(fileName, '.');
    if(!dot || dot == fileName) return "";
    return dot + 1;
}

void shuffleWallpapers() {
	int i, randNum;
	char *tmp;

	for (i = 0; i < fileNum; ++i) {
		randNum = rand() % fileNum;

		tmp = wallpaperFileNames[i];
		wallpaperFileNames[i] = wallpaperFileNames[randNum];
		wallpaperFileNames[randNum] = tmp;
	}
}