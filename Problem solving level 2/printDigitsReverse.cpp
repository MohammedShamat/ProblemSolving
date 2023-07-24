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

void printDigitsReverse(int number) {
	int reverse = 0;
	while (number > 0) {
		reverse = number % 10;
		cout << reverse << endl;
		number = number / 10;
	}
}


int main() {


	printDigitsReverse(readNumberFromUser("Please enter a positive number"));
}/*
 Please enter a positive number
ssafdss
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
1525
5
2
5
1

*/