#include<iostream>
#include<iomanip>
#include<cstdio>
using  namespace std;
int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
	return number;
}
void FillMatrix(short arr[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			arr[indexFirst][indexSec] = randomNumberFun(1, 10);
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
bool IsMatrixScalar(short matrix[3][3], short rows, short cols) {
	short tempFirstElement = matrix[0][0];
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			if (indexFirst == indexSec && matrix[indexFirst][indexSec] != tempFirstElement) {
				return false;
			}
			else if (indexFirst != indexSec && matrix[indexFirst][indexSec] != 0) {
				return false;
			}
		}
	}
	return true;
}
void PrintResult(bool result) {
	(result) ? cout << "\nYes : matrices is Scalar" : cout << "\nNo : matrices is not Scalar";
}
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	short unitMatrix[3][3] = { {25,0,0},
		{0,25,0},{0,0,25} };
	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);
	PrintResult(IsMatrixScalar(arrFirst, 3, 3));
	cout << "\nMatrix 2 :\n";
	PrintMatrix(unitMatrix, 3, 3);
	PrintResult(IsMatrixScalar(unitMatrix, 3, 3));
}
/*
output :
Matrix 1 :
 06      06      03
 10      01      08
 06      10      04

No : matrices is not Scalar
Matrix 2 :
 25      00      00
 00      25      00
 00      00      25

Yes : matrices is Scalar

or

Matrix 1 :
 10      07      10
 08      03      03
 05      06      01

No : matrices is not Scalar
Matrix 2 :
 25      50      00
 00      25      00
 00      00      25

No : matrices is not Scalar

*/