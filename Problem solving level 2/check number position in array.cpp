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
void printResult(short checkNumber) {
	if (checkNumber == -1) {

		cout << "The number is not found :-(";
	}
	else {
		cout << "The number found at positon : " << checkNumber << endl;
		cout << "The number found its order : " << checkNumber + 1;
	}


}



int main() {
	srand((unsigned)time(NULL));
	int array[100] = {};


	int countOfElements = readNumberFromUser("Please Enter number of elements ?");


	fillsTheArray(array, countOfElements);
	printTheArray(array, countOfElements);

	int numberToSearch = readNumberFromUser("\nPlease Enter a number to search in array ?");
	printResult(checkToNumber(array, countOfElements, numberToSearch));


}




/*
Please Enter number of elements ?
sss
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
10

Array Of Elements:
1 48 13 67 80 36 46 47 6 50
Please Enter a number to search in array ?
47
Number you are looking for is: 47
The number found at positon : 7
The number found its order : 8

OR

Please Enter number of elements ?
10

Array Of Elements:
33 14 46 81 35 82 100 13 88 40
Please Enter a number to search in array ?
95
Number you are looking for is: 95
The number is not found :-(
*/