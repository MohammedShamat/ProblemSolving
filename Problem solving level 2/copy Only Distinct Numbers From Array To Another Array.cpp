#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
void addArrayElement(int number, int arr[100], int& length) {
	arr[length] = number;
	length++;
}
short checkToNumber(int array[100], int length, int numberForCheck) {
	short counter = 0;
	for (int index = 0; index < length; index++) {

		if (array[index] == numberForCheck) {
			counter = index;
			return counter;
		}
	}
	return -1;
}
bool isNumberInArray(int array[100], int length, int numberForCheck) {
	return checkToNumber(array, length, numberForCheck) != -1;

}
void copyOnlyDistinctNumbersFromArrayToAnotherArray(int firstArr[100], int secondArr[100], int length, int& SecondArrLength) {
	for (short index = 0; index < length; index++) {

		if (!isNumberInArray(secondArr, SecondArrLength, firstArr[index])) {
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

	int array[100] = { 10,10,10,50,50,70,70,70,70,90,90,20,10,50,100,100 };

	int countOfElements = 16;
	int secondArr[100] = {};
	int secondArrLength = 0;


	cout << "Array Elements [";
	printTheArray(array, countOfElements);
	cout << "]\n";
	copyOnlyDistinctNumbersFromArrayToAnotherArray(array, secondArr, countOfElements, secondArrLength);
	cout << "Copy distinct Number Array Elements  [";
	printTheArray(secondArr, secondArrLength);
	cout << "]";

}



/*
Array Elements [10 10 10 50 50 70 70 70 70 90 90 20 10 50 100 100 ]
Copy distinct Number Array Elements  [10 50 70 90 20 100 ]
*/