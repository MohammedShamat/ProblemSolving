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
char InvertCharacter(char charFromUser) {
	return islower(charFromUser) ? toupper(charFromUser) : tolower(charFromUser);

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

	cout << "Letter \'" << valueFromUser << "\' count :" << CountOfCharacter(textFromUser, valueFromUser) << endl;

}
int main() {
	string fromUser = ReadFromUser("Please Enter Your Text?");
	char fromUserChar = ReadCharFrpmUser("Please Enter a character to search?");
	PrintResult(fromUser, fromUserChar);
	PrintResult(fromUser, InvertCharacter(fromUserChar));
	cout << "Letter \'" << fromUserChar << "\' or \'" << InvertCharacter(fromUserChar) << " count =" << (CountOfCharacter(fromUser, fromUserChar) + CountOfCharacter(fromUser, InvertCharacter(fromUserChar)));
}

/*
output :

Please Enter Your Text?
Moahmmed Programming
Please Enter a character to search?
m
Letter 'm' count :4
Letter 'M' count :1
Letter 'm' or 'M count =5
*/