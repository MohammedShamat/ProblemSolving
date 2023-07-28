#include <iostream>
#include <string>
using namespace std;
bool palindromeArray(int array[100], int length) {
	for (int index = 0; index < length; index++) {
		if (array[index] != array[length - index - 1]) {
			return false;
		}
	}
	return true;
}
void printTheArray(int arr[100], int length) {
	for (int index = 0; index < length; index++) {
		cout << arr[index] << " ";
	}

}
void printResult(bool checkArray) {
	if (checkArray) {
		cout << "yes Array is Palindrome\n";
	}
	else {
		cout << "No Array is not Palindrome\n";
	}
}
int main() {

	int array[100] = { 10,20,30,30,20,10 };
	int sizeOfArray = 6;
	cout << "Array Elements [";
	printTheArray(array, sizeOfArray);
	cout << "]\n";
	printResult(palindromeArray(array, sizeOfArray));



}



/*
Array Elements [10 20 30 30 20 10 ]
yes Array is Palindrome

*/