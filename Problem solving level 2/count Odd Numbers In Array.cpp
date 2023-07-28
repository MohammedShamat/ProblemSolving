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
		cout << "please enter a correct value\n";
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

void fillsTheArray(int arr[100], int& length) {
	for (int index = 0; index < length; index++) {

		arr[index] = randomNumberFun(1, 100);
	}
	cout << endl;
}
int countOfOddNumberInArray(int firstArr[100], int length) {
	int counter = 0;
	for (short index = 0; index < length; index++) {
		if (checkNumberType(firstArr[index]) == enNumberType::odd) {
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
	cout << "Odd Numbers count is : " << countOfOddNumberInArray(array, sizeOfArray);


}



/*
Please Enter number of elements ?
dd
please enter a correct value
-99
please enter a correct value
0
please enter a correct value
5

Array Elements [10 79 24 85 100 ]
Odd Numbers count is : 2
*/