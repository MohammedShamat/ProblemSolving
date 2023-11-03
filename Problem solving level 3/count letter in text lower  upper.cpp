#include<iostream>
#include<string>
#include<cctype>
using  namespace std;
enum TypeOfLetter { Lower = 0, Upper = 1, AllType = 2 };
string ReadFromUser(string message) {
	cout << message << endl;
	string TextFromUser;
	getline(cin, TextFromUser);
	return TextFromUser;
}
short CountLetter(string textFromUser, TypeOfLetter whatWantToCount = TypeOfLetter::AllType) {
	short counter = 0;
	if (whatWantToCount == TypeOfLetter::AllType) {
		return textFromUser.length();
	}
	for (short index = 0; index < textFromUser.length(); index++) {
		if (isupper(textFromUser[index]) && whatWantToCount == TypeOfLetter::Upper) {
			counter++;
		}
		if (islower(textFromUser[index]) && whatWantToCount == TypeOfLetter::Lower) {
			counter++;
		}
	}
	return counter;
}
short lengthString(string textFromUser) {
	return textFromUser.length();
}

short CapitalLettersInString(string textFromUser) {
	short capitalLetters = 0;
	for (short index = 0; index < textFromUser.length(); index++) {
		if (isupper(textFromUser[index])) {
			capitalLetters++;
		}
	}
	return capitalLetters;
}
short LowerLettersInString(string textFromUser) {
	short lowerLetters = 0;
	for (short index = 0; index < textFromUser.length(); index++) {
		if (islower(textFromUser[index])) {
			lowerLetters++;
		}
	}
	return lowerLetters;
}

void PrintResult(string textFromUser) {
	cout << "String Length : \n" << lengthString(textFromUser) << endl;
	cout << "Capital Letters Count : \n" << CapitalLettersInString(textFromUser) << endl;
	cout << "Small Letters Count : \n" << LowerLettersInString(textFromUser) << endl;
}
int main() {
	string fromUser = ReadFromUser("Please Enter Your Text?");
	PrintResult(fromUser);
	cout << "**********General Method**********";
	cout << "\nLength :\n" << CountLetter(fromUser) << endl;
	cout << "\Capital Letters Count\n" << CountLetter(fromUser, TypeOfLetter::Upper) << endl;
	cout << "\Small Letters Count\n" << CountLetter(fromUser, TypeOfLetter::Lower) << endl;

}

/*
output :

Please Enter Your Text?
CONVERT each LETTER To LOWer oR UPPer
String Length :
37
Capital Letters Count :
21
Small Letters Count :
10
**********General Method**********
Length :
37
Capital Letters Count
21
Small Letters Count
10
*/