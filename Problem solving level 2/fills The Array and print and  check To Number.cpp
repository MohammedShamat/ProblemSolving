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

void fillsTheArray(int arr[100], int& length) {
	for (int index = 0; index < length; index++) {
		cout << "Please Enter Element [" << index + 1 << "] : ";
		cin >> arr[index];
	}
}
void printTheArray(int arr[100], int length) {
	for (int index = 0; index < length; index++) {
		cout << arr[index] << " ";
	}
}
short checkToNumber(int array[100], int length, int numberForCheck) {
	short counter = 0;
	for (int index = 0; index < length; index++) {
		if (array[index] == numberForCheck) {
			counter++;
		}
	}
	return counter;
}


int main() {

	int array[100] = {};

	int countOfElements = readNumberFromUser("Please Enter number of elements ?");
	int numberToCheck;
	fillsTheArray(array, countOfElements);
	numberToCheck = readNumberFromUser("\nPlease Enter the number you want to check it ?");
	cout << "Original array : ";
	printTheArray(array, countOfElements);
	cout << endl << numberToCheck << " is repeated " << checkToNumber(array, countOfElements, numberToCheck) << " times";
}



/*Please Enter number of elements ?
0
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
ss
Invalid Number, Enter a valid one
6
Please Enter Element [1] : 2
Please Enter Element [2] : 2
Please Enter Element [3] : 2
Please Enter Element [4] : 6
Please Enter Element [5] : 6
Please Enter Element [6] : 5

Please Enter the number you want to check it ?
5
Original array : 2 2 2 6 6 5
5 is repeated 1 times

OR

Please Enter number of elements ?
5
Please Enter Element [1] : 1
Please Enter Element [2] : 1
Please Enter Element [3] : 1
Please Enter Element [4] : 2
Please Enter Element [5] : 3

Please Enter the number you want to check it ?
1
Original array : 1 1 1 2 3
1 is repeated 3 times

*/