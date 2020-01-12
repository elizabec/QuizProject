#include <iostream>
#include <string>
#include "helper.h"

using namespace std;

class Quiz {
	friend istream& operator >> (istream& in, Quiz& q);
public:
	int askQ(int qnum = -1);
private:
	string question;
	string a1; //correct answer, always
	string a2;
	string a3;
	string a4;
};





