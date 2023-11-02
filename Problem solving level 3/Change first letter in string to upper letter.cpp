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
void PrintUpperFirstLetter(string userString) {
	char space = 32;
	bool isFirstLetter = true;
	for (short index = 0; userString.length() > index; index++) {
		if (userString[index] != space && isFirstLetter) {
			userString[index] = toupper(userString[index]);
		}

		isFirstLetter = (userString[index] == space) ? true : false;
	}
	cout << userString;

}

int main() {
	PrintUpperFirstLetter(ReadFromUser("Please Enter Your String?"));

}

/*
output :
Please Enter Your String?
test for upper case
Test For Upper Case
*/