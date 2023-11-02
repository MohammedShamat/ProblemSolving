#include<iostream>
#include<iomanip>
#include<cstdio>
using  namespace std;
int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
	return number;
}
short ReadNumberFromUser(string message) {
	cout << message << endl;
	short number;
	cin >> number;
	while (cin.fail() || number < 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}
void FillMatrix(short arr[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			arr[indexFirst][indexSec] = randomNumberFun(1, 50);
		}
	}
}
void PrintMatrix(short arr[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			printf(" %0*d\t", 2, arr[indexFirst][indexSec]);
		}
		cout << endl;
	}
}
bool IsThereNumber(short matrix[3][3], short numberToSearch, short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			if (matrix[indexFirst][indexSec] == numberToSearch) {
				return true;
			}
		}
	}
	return false;
}
void PrintResult(short result) {
	(result) ? cout << "Yes it is there" : cout << "No it is not there";
}
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);
	short number = ReadNumberFromUser("Enter the number to search in matrix ?");
	PrintResult(IsThereNumber(arrFirst, number, 3, 3));

}
/*
output :
Matrix 1 :
 04      09      09
 15      46      31
 14      35      12
Enter the number to count in matrix ?
12
Yes it is there
or
Matrix 1 :
 35      11      29
 25      45      10
 40      16      48
Enter the number to count in matrix ?
15
No it is not there
*/