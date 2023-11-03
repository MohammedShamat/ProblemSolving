#include<iostream>
#include<string>
#include<cctype>
using  namespace std;

string ReadFromUser(string message) {
	cout << message << endl;
	string TextFromUser = "";
	getline(cin, TextFromUser);
	return TextFromUser;
}
char ReadCharFrpmUser(string message) {
	char character = ' ';
	cout << message << endl;
	cin >> character;
	return character;
}
short CountOfCharacter(string textFromUser, char valueFromUser) {
	short counter = 0;
	for (short index = 0; index < textFromUser.length(); index++) {
		if (textFromUser[index] == valueFromUser) {
			counter++;
		}
	}
	return counter;
}
void PrintResult(string textFromUser, char valueFromUser) {

	cout << "Letter \'" << valueFromUser << "\' count :" << CountOfCharacter(textFromUser, valueFromUser);
}
int main() {
	string fromUser = ReadFromUser("Please Enter Your Text?");
	char fromUserChar = ReadCharFrpmUser("Please Enter a character to search?");
	PrintResult(fromUser, fromUserChar);
}

/*
output :

Please Enter Your Text?
CONVERT each LETTER To LOWer oR UPPer
Please Enter a character to search?
R
Letter R count :3
*/