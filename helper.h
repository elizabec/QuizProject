#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <cctype>
#include <iomanip>

void begin();
void menu_options();
void addQuestion();
void deleteFile();
void qList();
void startGame();

#define INVALID "Invalid input!\n"
#define NOFILE "Error, file not found!"
#define FILENAME "quiz.txt"
#define WIDTH 5
#define ANSWERS 3
#define QUESTIONS 5
#define BLANK ""
#define CORRECT "Enter correct answer: "
#define ALTERNATIVE "Enter alternative"
#define PERFECT "Perfect score, well done!"
#define ALMOST "Almost there, but not quite!"
#define BETTER "Better luck next time!"
#define NOPE "You get NOTHING. You LOSE. Good DAY Sir!"