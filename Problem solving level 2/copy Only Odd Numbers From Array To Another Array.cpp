#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
enum enNumberType { odd = 1, even = 2 };

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
enNumberType checkNumberType(int number) {
	int result = number % 2;
	if (result == 0)
		return enNumberType::even;
	else
		return enNumberType::odd;
}

int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
	return number;

}
void addArrayElement(int number, int arr[100], int& length) {


	arr[length] = number;
	length++;

}

void fillsTheArray(int arr[100], int& length) {
	for (int index = 0; index < length; index++) {

		arr[index] = randomNumberFun(1, 100);
	}
	cout << endl;
}
void copyOnlyOddNumbersFromArrayToAnotherArray(int firstArr[100], int secondArr[100], int length, int& SecondArrLength) {
	for (short index = 0; index < length; index++) {

		if (checkNumberType(firstArr[index]) == enNumberType::odd) {
			addArrayElement(firstArr[index], secondArr, SecondArrLength);

		}


	}
}

void printTheArray(int arr[100], int length) {
	for (int index = 0; index < length; index++) {
		cout << arr[index] << " ";
	}

}




int main() {
	srand((unsigned)time(NULL));
	int array[100] = {};

	int countOfElements = readNumberFromUser("Please Enter number of elements ?");
	int secondArr[100] = {};
	int secondArrLength = 0;
	fillsTheArray(array, countOfElements);

	cout << "Array Elements [";
	printTheArray(array, countOfElements);
	cout << "]\n";
	copyOnlyOddNumbersFromArrayToAnotherArray(array, secondArr, countOfElements, secondArrLength);
	cout << "Copy Odd Number Array Elements  [";
	printTheArray(secondArr, secondArrLength);
	cout << "]";

}



/*
Please Enter number of elements ?
-99
Invalid Number, Enter a valid one
sss
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
5

Array Elements [76 74 95 83 42 ]
Copy Odd Number Array Elements  [95 83 ]
*/