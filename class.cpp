#include "class.h"
#include "helper.h"

using namespace std;

void answer_shuffle(vector<string>& a, vector<string>& b);

int Quiz::askQ(int qnum) {
	int score = 0, guess, n = 1;
	vector<string> answers = { a1 }; //making seperate vector of answers that definitely contains correct answer
	vector<string> incorrect = { a2, a3, a4 }; //vector of incorrect answers
	vector<string>::iterator it; //iterator

	if (qnum > 0) {
		cout << "Q" << qnum << ":"; //print current question number
	}
	for (int i = 3; i < question.length(); i++) { //print question without "Qx" tag
		cout << question[i];
	}

	answer_shuffle(answers, incorrect);

	it = find(answers.begin(), answers.end(), a1); //iterate to correct answer (a1)
	int index = distance(answers.begin(), it); //get index number of correct answer
	int correct = index + 1; //since index number != answer number

	cout << endl;
	for (int j = 0; j < ANSWERS; j++) { //automating answer output
		cout << n << ") " << answers[j] << endl;
		n++;
	}
	do {
		cout << "Enter your answer (1 - 3): ";
		cin >> guess;
		if (guess < 1 || guess > 3) {
			cout << INVALID;
			cin.clear();
			char(cin.get());
		}
	} while (guess < 1 || guess > 3);
	if (guess == correct) {
		cout << "Correct!\n\n";
		score++;
	}
	else {
		cout << "Incorrect!\n\n";
	}
	return score;
}




