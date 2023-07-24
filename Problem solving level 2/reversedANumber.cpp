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

int reversedANumber(int number) {

	int numberTemp = 0;

	int reverseNumber = 0;

	while (number > 0) {
		numberTemp = number % 10;

		number = number / 10;
		reverseNumber = reverseNumber * 10 + numberTemp;
	}

	return reverseNumber;
}



int main() {

	cout << "Reverse Number is " << reversedANumber(readNumberFromUser("Please enter a positive number"));

}
/* output
Please enter a positive number
dsd
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
14569
Reverse Number is 96541


 */