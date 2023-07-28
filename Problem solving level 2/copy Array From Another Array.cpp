#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

int readNumberFromUser(string message) {
	int number;
	cout << message << endl;
	cin >> number;
		while (cin.fail()|| number<=0) {
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
void copyArrayFromAnotherArray(int firstArr[100], int secondArr[100], short length) {
	for (short index = 0; index < length; index++) {
		secondArr[index] = firstArr[index];
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
	fillsTheArray(array, countOfElements);

	cout << "Array Elements [";
	printTheArray(array, countOfElements);
	cout << "]\n";
	copyArrayFromAnotherArray(array, secondArr, countOfElements);
	cout << "Copy Array Elements  [";
	printTheArray(secondArr, countOfElements);
	cout << "]";

}



/*
Please Enter number of elements ?
-99
Invalid Number, Enter a valid one
dd
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
5

Array Elements [29 8 97 61 31 ]
Copy Array Elements  [29 8 97 61 31 ]
*/