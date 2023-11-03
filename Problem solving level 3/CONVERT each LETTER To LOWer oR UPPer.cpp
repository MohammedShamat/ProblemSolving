#include<iostream>
#include<string>
#include<cctype>
using  namespace std;
string ReadFromUser(string message) {
	cout << message << endl;
	string TextFromUser;
	getline(cin, TextFromUser);
	return TextFromUser;
}
bool IsLowerLetter(char readChar) {
	return islower(readChar);
}

char InvertCharacter(char charFromUser) {
	return IsLowerLetter(charFromUser) ? toupper(charFromUser) : tolower(charFromUser);

}
string InvertString(string textFromUser) {
	for (short index = 0; index < textFromUser.length(); index++) {
		textFromUser[index] = InvertCharacter(textFromUser[index]);
	}
	return textFromUser;
}
void PrintResult(string textFromUser) {
	cout << "String after inverting all letters case : \n" << textFromUser << endl;
}
int main() {
	string fromUser = ReadFromUser("Please Enter Your Text?");
	PrintResult(InvertString(fromUser));
}

/*
output :

Please Enter Your Text?
CONVERT each LETTER To LOWer oR UPPer
String after inverting all letters case :
convert EACH letter tO lowER
*/