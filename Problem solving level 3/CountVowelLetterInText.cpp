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
bool IsVowelLetter(char& letter) {
	letter = tolower(letter);
	return ('a' == letter || 'e' == letter || 'o' == letter || 'i' == letter || 'u' == letter);
}
short CountVowelLetterInText(string textFromUser) {
	short counter = 0;
	for (short index = 0; index < textFromUser.length(); index++) {
		if (IsVowelLetter(textFromUser[index])) {
			counter++;
		}
	}
	return counter;
}

void PrintResult(short counter) {

	cout << "Number of Vowels is : " << counter;
}
int main() {
	string fromUserChar = ReadFromUser("Please Enter your text?");
	PrintResult(CountVowelLetterInText(fromUserChar));
}

/*
output :

Please Enter your text?
Mohammed Abu Hadhoud Programming Advices
Number of Vowels is : 14
*/