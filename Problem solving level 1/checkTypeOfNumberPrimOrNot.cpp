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
	while (cin.fail() || number<=0) {
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

int main()
{
	printResult(readPositiveNumberFromUser("Please Enter a positive number ?\n"));

}/*
 Please Enter a positive number ?

gdffd
Invalid Number, Enter a valid one
55
The number is not prime
*/