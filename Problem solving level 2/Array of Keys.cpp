#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

int readNumberFromUser(string message) {
	int number;

	cout << message << endl;
	cin >> number;
	while (cin.fail() || number <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}

enum CharType {
	SmallLetter = 1,
	CapitalLetter = 2,
	SpecialCharacter = 3,
	DigitNumber = 4,
};

int randomNumber(short from, short to) {

	int number = rand() % (to - from + 1) + from;
	return number;

}

char getRandomCharacter(CharType tyepOfChar) {
	switch (tyepOfChar)
	{
	case CharType::SmallLetter:
		return char(randomNumber(97, 122));

	case CharType::CapitalLetter:
		return char(randomNumber(65, 90));

	case CharType::DigitNumber:
		return char(randomNumber(48, 57));

	case CharType::SpecialCharacter:
		return char(randomNumber(33, 47));

	}
}

string generateWord(CharType typeOfChar, short length) {

	string word = "";
	for (short counter = 1; counter <= length; counter++) {
		word = word + getRandomCharacter(typeOfChar);
	}
	return word;
}


string generateKey() {
	string key = "";
	string underScore = "-";
	key = generateWord(CharType::CapitalLetter, 4) + underScore;
	key = key + generateWord(CharType::CapitalLetter, 4) + underScore;
	key = key + generateWord(CharType::CapitalLetter, 4) + underScore;
	key = key + generateWord(CharType::CapitalLetter, 4);
	return key;
}

void generateKeys(int numberOfKeys) {
	for (int counter = 1; counter <= numberOfKeys; counter++) {
		cout << "Key [" << counter << "] : " << generateKey() << endl;
	}
}
void arrayOfKeys(string arrayKeys[100], int length) {
	for (int index = 0; index < length; index++) {
		arrayKeys[index] = generateKey();

	}
}



void printTheArray(string arr[100], int length) {
	cout << "Array Elements :\n";
	for (int index = 0; index < length; index++) {

		cout << "Array [" << index + 1 << "]:" << arr[index] << "\n";

	}
}
int main() {

	srand((unsigned)time(NULL));

	string arr[100];

	int length = readNumberFromUser("Pleaes enter how many keys to generate ?");
	arrayOfKeys(arr, length);
	printTheArray(arr, length);

}



/*
Pleaes enter how many keys to generate ?
ss
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
5
Array Elements :
Array [1]:ILHK-UWWJ-ZPFA-DRGK
Array [2]:DGIA-GMMX-ZURP-VQTA
Array [3]:AXJI-ETAO-MZCZ-LROS
Array [4]:BQTA-COGZ-LCVD-PFNV
Array [5]:GLXM-QGTK-NFSK-SBOQ


*/