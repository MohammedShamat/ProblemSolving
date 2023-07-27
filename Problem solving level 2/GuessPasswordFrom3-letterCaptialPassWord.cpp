#include <iostream>
#include <string>
using namespace std;

string readPasswordFromUser(string message) {
	string passwordFromUser = "";
	cout << message << endl;
	cin >> passwordFromUser;
	return passwordFromUser;
}

bool cuessPassword(string passwordFromUser) {
	string cuessPassword = "";
	int counter = 0;

	for (short firstLetter = 65; firstLetter <= 90; firstLetter++) {
		for (short secondeLetter = 65; secondeLetter <= 90; secondeLetter++) {
			for (short thirdLetter = 65; thirdLetter <= 90; thirdLetter++) {
				cuessPassword = cuessPassword + char(firstLetter);
				cuessPassword = cuessPassword + char(secondeLetter);
				cuessPassword = cuessPassword + char(thirdLetter);
				cout << endl;
				counter++;
				cout << "Trail[" << counter << "] : " << cuessPassword << "\n";

				if (passwordFromUser == cuessPassword) {
					cout << "\npassword is " << cuessPassword << endl;
					cout << "Found after " << counter << " trials";

					return true;
				}
				else {
					cuessPassword = "";

				}


			}
		}
	}

}


int main() {

	cuessPassword(readPasswordFromUser("Please Enter a 3-letter PassWord(All Caiptal)"));
	return 0;
}/*



Please Enter a 3-letter PassWord(All Caiptal)
AAF

output is :

Trail[1] : AAA

Trail[2] : AAB

Trail[3] : AAC

Trail[4] : AAD

Trail[5] : AAE

Trail[6] : AAF

password is AAF
Found after 6 trials
 */