#include<iostream>
#include<string>
#include <vector>
using  namespace std;
string ReadFromUser(string message) {
	cout << message << endl;
	string userString = "";
	getline(cin, userString);
	return userString;
}
void PrintFirstLetter(string userString) {
	char space = 32;
	bool isFirstLetter = true;
	for (short index = 0; userString.length() > index; index++) {
		if (userString[index] != space && isFirstLetter) {
			cout << userString[index] << endl;
		}
		isFirstLetter = (userString[index] == space) ? true : false;

	}
}

int main() {
	PrintFirstLetter(ReadFromUser("Please Enter Your String?"));
}

/*
output :
Please Enter Your String?
c++ problem Solving string flaot @
c
p
S
s
f
@
*/