#include <iostream>
#include <string>
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

void printLetterPattern(int number) {

	cout << "letter pattern as follows \n\n";
	short letter = 65;
	for (short temp = 1; temp <= number; temp++) {
		for (short counter = 1; counter <= temp; counter++) {

			cout << char(letter);

		}
		letter++;
		cout << endl;

	}

}


int main() {

	printLetterPattern(readNumberFromUser("Please Enter a number"));

}/*

Please Enter a number
sdd
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
10
letter pattern as follows

A
BB
CCC
DDDD
EEEEE
FFFFFF
GGGGGGG
HHHHHHHH
IIIIIIIII
JJJJJJJJJJ
 */