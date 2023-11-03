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
void PrintAllVowelLetterInText(string textFromUser) {
	cout << "Vowels in string are : ";
	for (short index = 0; index < textFromUser.length(); index++) {
		if (IsVowelLetter(textFromUser[index])) {
			cout << textFromUser[index] << "\t";
		}
	}

}


int main() {
	string fromUserChar = ReadFromUser("Please Enter your text?");
	PrintAllVowelLetterInText(fromUserChar);
}

/*
output :

Please Enter your text?
automatically close the console when debugging stops
Vowels in string are : a        u       o       a       i       a       o       e       e       o       o       e      ee       u       i       o
*/