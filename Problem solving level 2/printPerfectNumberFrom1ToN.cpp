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
bool checkTypeNumber(int number) {
	int sum = 0;
	for (int counter = 1; counter < number; counter++) {

		if (number % counter == 0) {
			sum += counter;
		}

	}
	return number == sum;
}
void printResult(int number) {

	if (checkTypeNumber(number)) {
		cout << number << " is A perfect Number\n";
	}

}




void printPerfectNumberFrom1ToN(int number) {
	for (int loop = 1; loop <= number; loop++) {

		printResult(loop);
	}

}
int main() {

	printPerfectNumberFrom1ToN(readNumberFromUser("Please Enter a positive number"));

}/*
 Please Enter a positive number
ffa
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
100
6 is A perfect Number
28 is A perfect Number
*/