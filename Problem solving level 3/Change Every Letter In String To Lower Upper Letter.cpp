#include<iostream>
#include<string>
#include<cctype>
using  namespace std;
string ReadFromUser(string message) {
	cout << message << endl;
	string userString = "";
	getline(cin, userString);
	return userString;
}
void  ChangeLetterInStringToLowerLetter(string userString) {
	char space = 32;
	for (short index = 0; userString.length() > index; index++) {
		if (userString[index] != space) {
			userString[index] = tolower(userString[index]);
		}
	}
	cout << userString << endl;

}
void  ChangeLetterInStringToUpperLetter(string userString) {
	char space = 32;
	for (short index = 0; userString.length() > index; index++) {
		if (userString[index] != space) {
			userString[index] = toupper(userString[index]);
		}
	}
	cout << userString << endl;

}

int main() {
	string fromUser = ReadFromUser("Please Enter Your String?");
	cout << "\n*String after lower case*\n";
	ChangeLetterInStringToLowerLetter(fromUser);
	cout << "\n*String after upper case*\n";
	ChangeLetterInStringToUpperLetter(fromUser);
}

/*
output :

Please Enter Your String?
Test Change Every Letter In String To Lower/ Upper Letter

*String after lower case*
test change every letter in string to lower/ upper letter

*String after upper case*
TEST CHANGE EVERY LETTER IN STRING TO LOWER/ UPPER LETTER
*/