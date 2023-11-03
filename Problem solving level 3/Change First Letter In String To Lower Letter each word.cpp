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
void  ChangeFirstLetterInStringToLowerLetter(string userString) {
	char space = 32;
	bool isFirstLetter = true;
	for (short index = 0; userString.length() > index; index++) {
		if (userString[index] != space && isFirstLetter) {
			userString[index] = tolower(userString[index]);
		}

		isFirstLetter = (userString[index] == space) ? true : false;
	}
	cout << userString;

}

int main() {
	ChangeFirstLetterInStringToLowerLetter(ReadFromUser("Please Enter Your String?"));

}

/*
output :
Please Enter Your String?
Test Change First Letter In String To Lower Letter
test change first letter in string to lower letter
*/