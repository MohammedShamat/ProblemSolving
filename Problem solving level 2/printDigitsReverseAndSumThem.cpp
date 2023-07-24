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

void printDigitsReverseAndSumThem(int number) {

	int reverse = 0;
	int sumThem = 0;

	while (number > 0) {
		reverse = number % 10;
		cout << reverse << endl;
		number = number / 10;
		sumThem += reverse;
	}
	cout << "Sum Of Digits is " << sumThem;
}



int main() {

	printDigitsReverseAndSumThem(readNumberFromUser("Please enter a positive number"));
}/*
 Please enter a positive number
dsg
Invalid Number, Enter a valid one
-896
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
456
6
5
4
Sum Of Digits is 15
 */