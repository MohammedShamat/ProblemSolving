#include<iostream>
#include<iomanip>
#include<cstdio>
#include <vector>
using  namespace std;
int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
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
void InsterNumbersToArr(short firstMatrix[3][3], short secondMatrix[3][3], vector<short>& arr, short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			if (IsThereNumber(firstMatrix, secondMatrix[indexFirst][indexSec], 3, 3)) {
				arr.push_back(secondMatrix[indexFirst][indexSec]);
			}
		}
	}
}
void PrintVector(vector<short>& arr) {
	cout << "Intersected nummbers are :\n";
	for (short& number : arr) {

		cout << number << "\t";
	}
}
int main() {
	srand((unsigned)time(NULL));
	short firstMatrix[3][3];
	short secondMatrix[3][3];
	vector<short> arr;
	FillMatrix(firstMatrix, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(firstMatrix, 3, 3);
	FillMatrix(secondMatrix, 3, 3);
	cout << "Matrix 2 :\n";
	PrintMatrix(secondMatrix, 3, 3);
	InsterNumbersToArr(firstMatrix, secondMatrix, arr, 3, 3);
	PrintVector(arr);


}
/*
output :
Matrix 1 :
 08      18      14
 06      17      37
 02      11      40
Matrix 2 :
 14      18      09
 37      08      35
 17      42      27
Intersected nummbers are :
14      18      37      8       17
*/