#include "helper.h"
#include "class.h"

using namespace std;

void load(istream& in, vector<Quiz>& qs);
void shuffle_q(vector<Quiz>& qs);
void shuffle_a(vector<string>& a);
void results(vector<Quiz>& q);

void begin() {
	cout << "Welcome to the Quiz!" << endl;	
}

void menu_options() {
	cout << "Please select an option:" << endl;
	cout << "1: Start a new game\n2: Add a new question\n3: See all questions\n4: Clear all\n5: Quit\n\n";
}

void addQuestion() {
	fstream qfile;
	qfile.open(FILENAME, ios::in);
	if (!qfile) {
		cout << NOFILE;
	}

	int qno = 0;
	while (qfile) { //get next free question number
		string line;
		getline(qfile, line);
		qno++;
	}
	qno = (qno / 6) + 1; //set next available question number
	qfile.close();

	fstream file;
	file.open(FILENAME, ios::app);
	if (!file) {
		cout << NOFILE;
	}
	char option, x;
	do {
		string input, str;
		int correct;
		do {
			cout << "Do you want to add new question (Y/N)? ";
			cin >> option;
			option = toupper(option);
			if (option != 'N' && option != 'Y') { //validating input for Y/N
				cout << INVALID;
			}
		} while (option != 'N' && option != 'Y');
		if (option == 'n' || option == 'N') {
			break;
		}
		else if (option == 'y' || option == 'Y') {

			file << endl;
			do { // making sure input is not empty
				cout << "Enter your question: ";
				cin.get(x); // waiting for user input
				getline(cin, input);
				if (input == BLANK) {
					cout << INVALID;
				}
			} while (input == BLANK);
			str = "Q";
			str.append(to_string(qno)); //Add Qx tag to each question, x = question number
			str.append(": ");
			file << left;
			file << setw(WIDTH) << str;
			qno++;
			file << input << endl;
			// input for all 4 answers, making sure it's a valid input
			do { 
				cout << CORRECT;
				getline(cin, input);
				if (input == BLANK) {
					cout << INVALID;
				}
			} while (input == BLANK);
			str = input;
			file << str << endl;
			do {
			cout << ALTERNATIVE << " 1: ";
			getline(cin, input);
				if (input == BLANK) {
					cout << INVALID;
				}
			} while (input == BLANK);
			str = input;
			file << str << endl;

			do {
				cout << ALTERNATIVE << " 2: ";
				getline(cin, input);
				if (input == BLANK) {
					cout << INVALID;
				}
			} while (input == BLANK);
			str = input;
			file << str << endl;
			do {
				cout << ALTERNATIVE << " 3: ";
				getline(cin, input);
				if (input == BLANK) {
					cout << INVALID;
				}
			} while (input == BLANK);
			str = input;
			file << str << endl;

		}
		else {
			cout << INVALID;
		}
		cout << "\n";

	} while (option == 'Y' || option == 'y');

	file.close();
}

void deleteFile() {
	ofstream file;
	file.open(FILENAME, ios::out | ios::trunc); //truncate file to nothing, effectively deleting all contents
	if (!file) { //still got to check if the file is there
		cout << NOFILE;
	}
	file.close();
}

void qList() {
	ifstream file;
	string line;
	file.open(FILENAME);
	if (!file) { //yoohoo, any files home?
		cout << NOFILE;
	}
	while (file) {
		getline(file, line);
		if (line[0] == 'Q') { //Only print lines with Qx tag
			cout << line << endl;
		}
	}
	file.close();
}

istream& operator >> (istream& in, Quiz& q) {
	string line;
	while (getline(in, line)) {
		if (line.size() == 0) { //skip blank lines
			continue;
		}
		break;
	}
	// loading from file into class
	q.question = line;
	getline(in, q.a1);
	getline(in, q.a2);
	getline(in, q.a3);
	getline(in, q.a4);

	return in;
}

void load(istream& in, vector<Quiz>& qs) {
	Quiz nq;
	while (in >> nq) {
		qs.push_back(nq); //loading full question structures into vector
	}
}

void shuffle_q(vector<Quiz>& qs) {
	random_device rand_dev;
	mt19937 rand_gen(rand_dev()); //Mersenne Twister random generator
	shuffle(qs.begin(), qs.end(), rand_gen); //randomising the order of the questions
}

void shuffle_a(vector<string>& a) {
	random_device rand_dev;
	mt19937 rand_gen(rand_dev());
	shuffle(a.begin(), a.end(), rand_gen);
}

void answer_shuffle(vector<string>& a, vector<string>& b) {
	shuffle_a(b); //randomize incorrect answers
	b.pop_back(); //remove last incorrect answer, could be any of the three
	a.insert(a.end(), b.begin(), b.end()); //add remaining incorrect answers to answer vector
	shuffle_a(a); // randomize answers

}

void startGame() {
	ifstream file;
	file.open(FILENAME); //check if file still exists
	if (!file) {
		cout << NOFILE;
	}
	else {
		while (file) {
			vector<Quiz> nquiz;
			load(file, nquiz); //load questions and answers into vector
			shuffle_q(nquiz); //shuffle the questions
			results(nquiz); 
		}
	}
}

void results(vector<Quiz>& q) {
	int total = 0;

	for (int i = 0; i < QUESTIONS; ++i) {
		total += q[i].askQ(i + 1); //get score from askQ function, i = question number
	}
	cout << "You scored: " << total << " out of 5!\n";
	if (total == 5) {
		cout << PERFECT << "\n\n";
	}
	else if (total == 3 || total == 4) {
		cout << ALMOST << "\n\n";
	}
	else if (total == 1 || total == 2) {
		cout << BETTER << "\n\n";
	}
	else {
		cout << NOPE <<"\n\n";
	}
}


