#ifndef UI_MAIN
#define UI_MAIN

#include <stdio.h>
#include <conio.h>
#include <locale.h>

#include "dinamic_array.h"
#include "ui_manipulation.h"

#define SCREEEN_WIDTH 50
#define SCREEEN_HEIGHT 50

Canvas *mainCanvas;

void setupUI();

void updateUI();

#endif // UI_MAIN