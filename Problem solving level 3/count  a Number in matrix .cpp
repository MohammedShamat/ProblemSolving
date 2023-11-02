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
short CountNumber(short matrix[3][3], short numberToSearch, short rows, short cols) {
	short counter = 0;
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			if (matrix[indexFirst][indexSec] == numberToSearch) {
				counter++;
			}
		}
	}
	return counter;
}
void PrintResult(short result, short numberToSearch) {
	cout << "Number " << numberToSearch << " Count in matrix is : " << result << endl;
}
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);
	short number = ReadNumberFromUser("Enter the number to count in matrix ?");
	PrintResult(CountNumber(arrFirst, number, 3, 3), number);

}
/*
output :
Matrix 1 :
 19      13      36
 31      31      19
 44      15      16
Enter the number to count in matrix ?
31
Number 31 Count in matrix is : 2
*/