#include <iostream>
#include <string>
using namespace std;

void readNumbersFromUsers(float& num1, float& num2, float& num3) {
	cout << "Please Enter first Number to sum them...\n";
	cin >> num1;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> num1;
	}
	cout << "Please Enter Second Number to sum them...\n";
	cin >> num2;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> num2;
	}
	cout << "Please Enter Third Number to sum them...\n";
	cin >> num3;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> num3;
	}
}

float sumOfNumbers(float num1, float num2, float num3) {
	float result = num1 + num2 + num3;
	return result;
}
float avgOfNumbers(float num1, float num2, float num3) {
	return sumOfNumbers(num1, num2, num3) / 3;
}

void printSumOfNumbers(float numbers, float avg) {

	cout << "Sum Of numbers is = " << numbers << endl;
	cout << "Avg Of numbers is = " << avg << endl;
}

int main()
{

	float num1, num2, num3;
	readNumbersFromUsers(num1, num2, num3);
	printSumOfNumbers(sumOfNumbers(num1, num2, num3), avgOfNumbers(num1, num2, num3));
	return 0;

}/*
 Please Enter first Number to sum them...
ada
Invalid Number, Enter a valid one
12.6
Please Enter Second Number to sum them...
12.6
Please Enter Third Number to sum them...
12.9
Sum Of numbers is = 38.1
Avg Of numbers is = 12.7
 */