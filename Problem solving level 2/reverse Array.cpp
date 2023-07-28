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


void fillsTheArrayFrom1ToN(int arr[100], int length) {

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


void reverseArray(int firstArr[100], int secondeArr[100], int length) {
	short counter = length - 1;
	for (int index = 0; index < length; index++) {
		secondeArr[index] = firstArr[counter];
		--counter;
	}
	cout << endl;

}



int main() {
	srand((unsigned)time(NULL));
	int array[100] = {};
	int secondeArray[100] = {};

	int countOfElements = readNumberFromUser("Please Enter number of elements ?");




	fillsTheArrayFrom1ToN(array, countOfElements);
	cout << "Array Elements before shuffle \n[";
	printTheArray(array, countOfElements);
	cout << "]";
	reverseArray(array, secondeArray, countOfElements);
	cout << "Array Elements After reversed it \n[";
	printTheArray(secondeArray, countOfElements);
	cout << "]";



}




/*
Please Enter number of elements ?
da
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
10

Array Elements before shuffle
[41 61 69 52 88 89 87 57 20 94 ]
Array Elements After reversed it
[94 20 57 87 89 88 52 69 61 41 ]
*/