#include <iostream>
#include <string>
using namespace std;


void readNumbersFromUsers(int& number1, int& number2, int& number3) {

	cout << "Please Enter First number ...\n";
	cin >> number1;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number1;
	}

	cout << "Please Enter Second number ...\n";
	cin >> number2;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number2;
	}

	cout << "Please Enter Third number ...\n";
	cin >> number3;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number3;
	}

}

int checkMaxOfThreeNumbers(int firstNum, int secondNum, int ThirdNumber) {
	if (firstNum > secondNum && firstNum > ThirdNumber) {
		return firstNum;
	}
	else if (secondNum > ThirdNumber) {
		return secondNum;
	}
	else {
		return ThirdNumber;
	}


}






void printResult(int checkNum) {

	cout << "This Number is Bigger " << checkNum;

}

int main()
{
	int firstNumber, SecondNumber, thirdNumber;
	readNumbersFromUsers(firstNumber, SecondNumber, thirdNumber);
	printResult(checkMaxOfThreeNumbers(firstNumber, SecondNumber, thirdNumber));
	return 0;

}/*
 Please Enter First number ...
aaa
Invalid Number, Enter a valid one
12
Please Enter Second number ...
-50
Please Enter Third number ...
13
This Number is Bigger 13
 */