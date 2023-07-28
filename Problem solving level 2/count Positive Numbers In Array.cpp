#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
enum numberType { positive = 1, negative = 2 };

int readNumberFromUser(string message) {
	int number;

	cout << message << endl;
	cin >> number;
	while (cin.fail() || number <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "please enter a correct value\n";
		cin >> number;

	}
	return number;
}
numberType checkNumberType(int number) {

	if (number < 0)
		return numberType::negative;
	else
		return numberType::positive;
}

int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
	return number;

}

void fillsTheArray(int arr[100], int& length) {
	for (int index = 0; index < length; index++) {

		arr[index] = randomNumberFun(-100, 100);
	}
	cout << endl;
}
int countPositiveNumberInArray(int firstArr[100], int length) {
	int counter = 0;
	for (short index = 0; index < length; index++) {
		if (checkNumberType(firstArr[index]) == numberType::positive) {
			counter++;
		}
	}
	return counter;
}

void printTheArray(int arr[100], int length) {
	for (int index = 0; index < length; index++) {
		cout << arr[index] << " ";
	}

}




int main() {
	srand((unsigned)time(NULL));
	int array[100] = {};

	int sizeOfArray = readNumberFromUser("Please Enter number of elements ?");
	fillsTheArray(array, sizeOfArray);

	cout << "Array Elements [";
	printTheArray(array, sizeOfArray);
	cout << "]\n";
	cout << "Positive Numbers count is : " << countPositiveNumberInArray(array, sizeOfArray);


}



/*
Please Enter number of elements ?
dfd
please enter a correct value
-99
please enter a correct value
0
please enter a correct value
10

Array Elements [37 98 27 -38 85 -43 85 39 31 -27 ]
Positive Numbers count is : 7

*/