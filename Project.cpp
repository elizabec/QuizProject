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
				cin.clear();
				char(cin.get()); //flush unwanted character. No characters allowed in this buffer!
			}
		} while (option < 1 || option > 5);
		if (option >= 1 || option <= 5) {
			switch (option) {
			case 1:
				char choice;
				cout << "Do you want to start a new game (Y/N)? ";
				cin >> choice;
				choice = toupper(choice); //making character uppercase, for simplicity
				switch (choice) {
				case 'Y':
					cout << "Starting new game!\n\n";
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
				do {
					cout << "Are you sure you want to delete everything (Y/N)? "; //because we don't want any accidents
					cin >> filedel;
					filedel = toupper(filedel); //again, making char uppercase
					if (filedel != 'Y' && filedel != 'N') {
						cout << INVALID;
					}
				} while (filedel != 'Y' && filedel != 'N');
				
				switch (filedel) {
				case 'Y':
					deleteFile();
					cout << "Save file deleted!\n";
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