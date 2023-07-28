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
void sawp(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
	return number;

}


void fillsTheArrayFrom1ToN(int arr[100], int length) {

	for (int index = 0; index < length; index++) {

		arr[index] = index + 1;
	}
	cout << endl;
}


void printTheArray(int arr[100], int length) {

	for (int index = 0; index < length; index++) {
		cout << arr[index] << " ";
	}

}


void shuffleArray(int arr[100], int length) {

	for (int index = 0; index < length; index++) {

		sawp(arr[randomNumberFun(1, length)-1], arr[randomNumberFun(1, length)-1]);
	}
	cout << endl;

}



int main() {
	srand((unsigned)time(NULL));
	int array[100] = {};


	int countOfElements = readNumberFromUser("Please Enter number of elements ?");




	fillsTheArrayFrom1ToN(array, countOfElements);
	cout << "Array Elements before shuffle \n[";
	printTheArray(array, countOfElements);
	cout << "]";
	shuffleArray(array, countOfElements);
	cout << "Array Elements After shuffle \n[";
	printTheArray(array, countOfElements);
	cout << "]";



}




/*
Please Enter number of elements ?
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
fg
Invalid Number, Enter a valid one
10

Array Elements before shuffle
[1 2 3 4 5 6 7 8 9 10 ]
Array Elements After shuffle
[2 10 1 3 9 6 4 7 8 5 ]
*/