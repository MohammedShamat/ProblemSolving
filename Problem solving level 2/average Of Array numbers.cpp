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

int sumAllNumbersInArray(int array[100], int& length) {
	int sum = 0;
	for (int index = 0; index < length; index++) {

		sum = sum + array[index];

	}
	return sum;
}

float averageOfArray(int array[100], int& length) {

	float average = (float)sumAllNumbersInArray(array, length) / length;
	return average;
}



int main() {
	srand((unsigned)time(NULL));
	int array[100] = {};


	int countOfElements = readNumberFromUser("Please Enter number of elements ?");

	fillsTheArray(array, countOfElements);

	cout << "Array Elements [";
	printTheArray(array, countOfElements);
	cout << "]";

	cout << "\nAverage of all numbers in array :" << averageOfArray(array, countOfElements);

}




/*
Please Enter number of elements ?
ds
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
5

Array Elements [40 86 79 24 13 ]
Average of all numbers in array :48.4
*/