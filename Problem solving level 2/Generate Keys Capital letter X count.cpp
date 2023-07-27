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
	key = generateWord(CharType::CapitalLetter, 3) + underScore;
	key = key + generateWord(CharType::CapitalLetter, 3) + underScore;
	key = key + generateWord(CharType::CapitalLetter, 3) + underScore;
	key = key + generateWord(CharType::CapitalLetter, 3);
	return key;
}

void generateKeys(int numberOfKeys) {
	for (int counter = 1; counter <= numberOfKeys; counter++) {
		cout << "Key [" << counter << "] : " << generateKey() << endl;
	}
}

int main() {

	srand((unsigned)time(NULL));
	generateKeys(readNumberFromUser("Pleaes enter how many keys to generate ?"));
}



/*
Pleaes enter how many keys to generate ?
dd
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
5
Key [1] : GED-ROO-RHW-GDH
Key [2] : DBK-SRK-JMS-HXI
Key [3] : KPE-FPP-EQT-HVD
Key [4] : ILX-CKJ-RSE-WNX
Key [5] : KIV-EHP-FNQ-MBJ



*/