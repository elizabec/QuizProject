#include "helper.h"
#include "class.h"

using namespace std;

int main() {
	int option = 0;
	begin();
	do {
		menu_options();
		do {
			cout << "Your choice: ";
			cin >> option;
			if (option < 1 || option > 5) {
				cout << INVALID;
			}
		} while (option < 1 || option > 5);
		if (option >= 1 || option <= 5) {
			switch (option) {
			case 1:
				char choice;
				cout << "Do you want to start a new game (Y/N)? ";
				cin >> choice;
				choice = toupper(choice);
				switch (choice) {
				case 'Y':
					cout << "Starting new game!" << endl << endl;
					startGame();
					break;
				case 'N':
					cout << "Shame...\n";
					break;
				default:
					cout << INVALID;
					break;
				}
				break;
			case 2:
				addQuestion();
				break;
			case 3:
				cout << "All questions:\n\n";
				qList();
				cout << endl;
				break;
			case 4:
				char filedel;
				cout << "This option will complete clear the save file.\n";
				cout << "Are you sure you want to delete everything (Y/N)? ";
				cin >> filedel;
				filedel = toupper(filedel);
				switch (filedel) {
				case 'Y':
					deleteFile();
					cout << "Save file deleted!";
					break;
				case 'N':
					break;
				default:
					cout << INVALID;
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