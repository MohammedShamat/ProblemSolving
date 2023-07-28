#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
enum TypeNumber {
	primeNumber = 1,
	notPrimeNumber = 2,
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
TypeNumber checkTypeNumber(int number) {
	int halfOfRound = round(number / 2);
	for (short counter = 2; counter <= halfOfRound; counter++) {
		if (number % counter == 0) {
			return TypeNumber::notPrimeNumber;
		}
	}
	return TypeNumber::primeNumber;
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
void copyOnlyPrimeNumbersFromArrayToAnotherArray(int firstArr[100], int secondArr[100], int length, int& SecondArrLength) {
	for (short index = 0; index < length; index++) {

		if (checkTypeNumber(firstArr[index]) == TypeNumber::primeNumber) {
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
	copyOnlyPrimeNumbersFromArrayToAnotherArray(array, secondArr, countOfElements, secondArrLength);
	cout << "Copy Prime Number Array Elements  [";
	printTheArray(secondArr, secondArrLength);
	cout << "]";
}

/*
Please Enter number of elements ?
xx
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
10

Array Elements [10 80 23 23 17 57 42 85 51 81 ]
Copy Prime Number Array Elements  [23 23 17 ]
*/