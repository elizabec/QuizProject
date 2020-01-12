#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <cctype>
#include <limits>

void begin();
void menu_options();
void addQuestion();
void deleteFile();
void qList();
void startGame();

#define INVALID "Invalid input!\n"
#define NOFILE "Error, file not found!"
#define FILENAME "quiz.txt"
#define ANSWERS 3