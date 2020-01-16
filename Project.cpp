#include "helper.h"
#include "class.h"

using namespace std;

int main() {
	int option = 0;
	bool b = true;
	begin();
	do {
		menu_options();
		do {
			cout << "Your choice: ";
			cin >> option;
			if (option < 1 || option > 5) {
				cout << INVALID;
				cout << "Press Enter to try again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore strings and characters, no matter how long
				char(cin.get()); //flush unwanted character. No characters allowed in this buffer!
				
			}
		} while (option < 1 || option > 5);
		if (option >= 1 || option <= 5 && b == true) { // double checking if looping properly
			switch (option) {
			case 1:
				char choice;
				do {
					cout << "Do you want to start a new game (Y/N)? ";
					cin >> choice;
					choice = toupper(choice); //making character uppercase, for simplicity
					if (choice != 'Y' && choice != 'N') {
						cout << INVALID;
						cout << "Press Enter to try again.\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
						char(cin.get());
					}
				} while (choice != 'Y' && choice != 'N');
				switch (choice) {
				case 'Y':
					cout << "Starting new game!\n\n";
					startGame();
					break;
				case 'N':
					cout << "Shame...\n";
					break;
				}
				break;
			case 2:
				addQuestion();
				break;
			case 3:
				qList();
				cout << endl;
				break;
			case 4:
				char filedel;
				cout << "This option will complete clear the save file.\n";
				do {
					cout << "Are you sure you want to delete everything (Y/N)? "; //because we don't want any accidents
					cin >> filedel;
					filedel = toupper(filedel); //again, making char uppercase
					if (filedel != 'Y' && filedel != 'N') {
						cout << INVALID;
						cout << "Press Enter to try again...";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore
						char(cin.get()); //flush
					}
				} while (filedel != 'Y' && filedel != 'N');
				
				switch (filedel) {
				case 'Y':
					deleteFile();
					cout << "Save file deleted!\n";
					break;
				case 'N':
					break;
				}
				break;
			case 5:
				cout << "Goodbye!\n";
				break;
			default:
				cout << INVALID;
				break;
			}
		}
	} while (option != 5);
	
	return 0;
}