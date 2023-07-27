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

	cout << "inverted letter pattern as follows \n\n";

	for (short temp = number; temp > 0; temp--) {
		for (short counter = number; counter > 0; counter--) {

			cout << char(64 + number);

		}
		number--;
		cout << endl;

	}

}


int main() {

	printLetterPattern(readNumberFromUser("Please Enter a number"));

}/*

Please Enter a number
-99
Invalid Number, Enter a valid one
cfdfd
Invalid Number, Enter a valid one
5
inverted letter pattern as follows

EEEEE
DDDD
CCC
BB
A


 */