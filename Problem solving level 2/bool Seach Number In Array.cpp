#include <iostream>
#include <string>
#include<cstdlib>
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

int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
	return number;

}

void fillsTheArray(int arr[100], int length) {
	for (int index = 0; index < length; index++) {

		arr[index] = randomNumberFun(1, 100);
	}
	cout << endl;
}

void printTheArray(int arr[100], int length) {
	cout << "Array Of Elements:\n";
	for (int index = 0; index < length; index++) {
		cout << arr[index] << " ";
	}

}

short checkToNumber(int array[100], int length, int numberForCheck) {
	short counter = 0;

	cout << "Number you are looking for is: " << numberForCheck << endl;
	for (int index = 0; index < length; index++) {

		if (array[index] == numberForCheck) {
			counter = index;
			return counter;
		}

	}

	return -1;



}

bool SeachNumberInArray(int array[100], int length, short checkNumber) {
	return checkToNumber(array, length, checkNumber) != -1;

}
void printResult(bool checkNumber) {
	if (checkNumber) {

		cout << "Yes,The number found :-)";
	}
	else {

		cout << "No,The number is not found :-(";

	}


}



int main() {
	srand((unsigned)time(NULL));
	int array[100] = {};


	int countOfElements = readNumberFromUser("Please Enter number of elements ?");


	fillsTheArray(array, countOfElements);
	printTheArray(array, countOfElements);

	int numberToSearch = readNumberFromUser("\nPlease Enter a number to search in array ?");
	printResult(SeachNumberInArray(array, countOfElements, numberToSearch));


}




/*
Please Enter number of elements ?
dad
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
10

Array Of Elements:
2 1 61 6 55 81 48 85 23 53
Please Enter a number to search in array ?
6
Number you are looking for is: 6
Yes,The number found :-)

OR
Please Enter number of elements ?
10

Array Of Elements:
9 7 18 38 34 76 62 11 12 14
Please Enter a number to search in array ?
100
Number you are looking for is: 100
No,The number is not found :-(
*/