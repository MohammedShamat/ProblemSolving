#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

int readNumberFromUser(string message) {
	int number;

	cout << message << endl;
	cin >> number;
	while (cin.fail() || (number > 4 || number <= 0)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}

	return number;
}

enum random {
	SmallLetter = 1,
	CapitalLetter = 2,
	SpecialCharacter = 3,
	DigitNumber = 4,
};

string printScreenForUser() {
	string message = "Please press a number what you want\n";
	message += "for Small Letter = 1, Capital Letter = 2 Special Character = 3, DigitNUmber = 4.";
	return message;

}

int randomNumberFun(short from, short to) {

	int number = rand() % (to - from + 1) + from;
	return number;

}

random options(int choiceFromUser) {
	random check;
	check = (random)choiceFromUser;

	switch (check)
	{
	case random::SpecialCharacter:
		return random::SpecialCharacter;
	case random::CapitalLetter:
		return random::CapitalLetter;
	case random::DigitNumber:
		return random::DigitNumber;
	case random::SmallLetter:
		return random::SmallLetter;
	}

}

void printResult(random option) {
	switch (option)
	{
	case random::SpecialCharacter:
		cout << char(randomNumberFun(32, 47));
		break;
	case random::CapitalLetter:
		cout << char(randomNumberFun(65, 90));
		break;
	case random::DigitNumber:
		cout << randomNumberFun(1, 10);
		break;
	case random::SmallLetter:
		cout << char(randomNumberFun(97, 122));
		break;
	}

}


int main() {

	srand((unsigned)time(NULL));
	int choiceFromUser = readNumberFromUser(printScreenForUser());
	printResult(options(choiceFromUser));

}

/*

Please press a number what you want
for Small Letter = 1, Capital Letter = 2 Special Character = 3, DigitNUmber = 4.
5
Invalid Number, Enter a valid one
5
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
ddd
Invalid Number, Enter a valid one


1
u
output
2
B
output
3
)
output
4
56

*/