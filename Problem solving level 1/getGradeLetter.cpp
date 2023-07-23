#include <iostream>

using namespace std;

int readNumberInRange(int from, int to) {
	int number;
	cout << "Please enter a number in range from " << from << " to " << to << "?\n";
	cin >> number;
	while (cin.fail() || (number < from || number > to)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}
char getGradeLetter(int grade) {
	if (grade >= 90) {
		return 'A';
	}
	else if (grade >= 80) {
		return 'B';
	}
	else if (grade >= 70) {
		return 'C';
	}
	else if (grade >= 60) {
		return 'D';
	}
	else if (grade >= 50) {
		return 'E';
	}
	else {
		return 'F';
	}
}


int main() {

	cout << getGradeLetter(readNumberInRange(0, 100));
	return 0;

}/*
 output
 Please enter a number in range from 0 to 100?
ds
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
101
Invalid Number, Enter a valid one
99
A*/