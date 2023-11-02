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
bool IsMatrixIdentity(short arrFirst[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			if (indexFirst == indexSec && arrFirst[indexFirst][indexSec] != 1) {
				return false;
			}
			else if (indexFirst != indexSec && arrFirst[indexFirst][indexSec] != 0) {
				return false;
			}
		}
	}
	return true;
}
void PrintResult(bool result) {
	(result) ? cout << "\nYes : matrices is Identity" : cout << "\nNo : matrices is not Identity";
}
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	short unitMatrix[3][3] = { {1,0,0},
		{0,1,0},{0,0,1} };
	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);
	PrintResult(IsMatrixIdentity(arrFirst, 3, 3));
	cout << "\nMatrix 2 :\n";
	PrintMatrix(unitMatrix, 3, 3);
	PrintResult(IsMatrixIdentity(unitMatrix, 3, 3));
}
/*
output :
Matrix 1 :
 10      09      07
 04      09      07
 03      02      02

No : matrices is not Identity
Matrix 2 :
 01      00      00
 00      01      00
 00      00      01

Yes : matrices is Identity

*/