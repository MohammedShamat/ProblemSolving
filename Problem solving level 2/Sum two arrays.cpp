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

	for (int index = 0; index < length; index++) {
		cout << arr[index] << " ";
	}

}
void sumTwoArrays(int firstArray[100], int secondArray[100], int sumTwoArrays[100], int length) {

	for (int index = 0; index < length; index++) {
		sumTwoArrays[index] = firstArray[index] + secondArray[index];
	}
	cout << endl;
}


int main() {
	srand((unsigned)time(NULL));
	int array[100] = {};
	int arraySecond[100] = {};
	int sumArrays[100] = {};
	int countOfElements = readNumberFromUser("Please Enter number of elements ?");

	fillsTheArray(array, countOfElements);

	cout << "First Array Elements \n[";
	printTheArray(array, countOfElements);
	cout << "]";

	fillsTheArray(arraySecond, countOfElements);
	cout << "\nSecond Array Elements \n[";
	printTheArray(arraySecond, countOfElements);
	cout << "]";

	sumTwoArrays(array, arraySecond, sumArrays, countOfElements);

	cout << "\nSum First And Second Arrays Elements \n[";
	printTheArray(sumArrays, countOfElements);
	cout << "]";

}




/*
Please Enter number of elements ?
ss
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
5

First Array Elements
[54 70 40 43 73 ]

Second Array Elements
[91 6 83 26 47 ]

Sum First And Second Arrays Elements
[145 76 123 69 120 ]
*/