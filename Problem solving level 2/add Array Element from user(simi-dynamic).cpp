#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

int readNumberFromUser(string message) {
	int number;
	cout << message << endl;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}
void addArrayElement(int number, int arr[100], int& length) {
	arr[length] = number;
	length++;
	cout << endl;
}
void inputUserNumberInArray(int arr[100], int& length) {
	bool addMore = 1;
	do {
		addArrayElement(readNumberFromUser("Please Enter a number"), arr, length);
		cout << "Do you want to add more numbers [0]:No,[1]yes? ";
		cin >> addMore;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one\n";
			cin >> addMore;
		}
	} while (addMore);
}
void printTheArray(int arr[100], int length) {
	cout << "Array length is: " << length << endl;
	cout << "Array Of Elements:\n";
	for (int index = 0; index < length; index++) {
		cout << arr[index] << " ";
	}

}
int main() {
	int array[100];
	int index = 0;
	inputUserNumberInArray(array, index);

	printTheArray(array, index);

}




/*
lease Enter a number
10

Do you want to add more numbers [0]:No,[1]yes? dddd
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
2
Invalid Number, Enter a valid one
3
Invalid Number, Enter a valid one
1
Please Enter a number
15

Do you want to add more numbers [0]:No,[1]yes? 0
Array length is: 2
Array Of Elements:
10 15
*/