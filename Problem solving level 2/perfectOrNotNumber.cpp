#include <iostream>
#include <string>
using namespace std;

enum perfectOrNot {
	perfect = 1,
	NotPerfect = 2,
};


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
perfectOrNot checkTypeNumber(int number) {
	int sum = 0;
	for (int counter = 1; counter < number; counter++) {

		if (number % counter == 0) {
			sum += counter;
		}

	}
	if (number == sum) {
		return perfectOrNot::perfect;
	}
	else {
		return perfectOrNot::NotPerfect;
	}
}
void printResult(perfectOrNot checkTypeNumber) {
	switch (checkTypeNumber)
	{
	case perfectOrNot::perfect:
		cout << "is perfect number";
		break;
	case perfectOrNot::NotPerfect:
		cout << "is not perfect number";
		break;

	}

}
int main() {

	printResult(checkTypeNumber(readNumberFromUser("Please Enter a positive number")));

}/*
 
 Please Enter a positive number
ffvf
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
15
is not perfect number
or

Please Enter a positive number
6
is perfect number */