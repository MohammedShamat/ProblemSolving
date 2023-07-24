#include <iostream>
#include <string>
using namespace std;

enum TypeNumber {
	primeNumber = 1,
	notPrimeNumber = 2,
};
float readPositiveNumberFromUser(string message) {

	float number;

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
TypeNumber checkTypeNumber(int number) {

	int halfOfRound = round(number / 2);
	for (short counter = 2; counter <= halfOfRound; counter++) {
		if (number % counter == 0) {
			return TypeNumber::notPrimeNumber;
		}

	}
	return TypeNumber::primeNumber;

}
void printResult(int number) {

	switch (checkTypeNumber(number))
	{
	case TypeNumber::notPrimeNumber:
		cout << "The number is not prime\n";
		break;
	case TypeNumber::primeNumber:
		cout << "The number is prime\n";
		break;
	}

}
void printAllNumberFrom1ToN(int number) {
	for (int loop = 1; loop <= number; loop++) {

		if (checkTypeNumber(loop) == TypeNumber::primeNumber) {
			cout << loop << " The number is prime\n";

		};
	}
}

int main() {
	printAllNumberFrom1ToN(readPositiveNumberFromUser("Please Enter A Positive Number"));
}




/*
* output
Please Enter A Positive Number
css
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
11
1 The number is prime
2 The number is prime
3 The number is prime
5 The number is prime
7 The number is prime
11 The number is prime


*/