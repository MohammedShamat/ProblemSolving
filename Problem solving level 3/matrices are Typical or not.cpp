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
bool IsMatrixTypical(short arrFirst[3][3], short arrSecond[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			if (arrFirst[indexFirst][indexSec] != arrSecond[indexFirst][indexSec]) {
				return false;
			};

		}
	}
	return true;
}
void PrintResult(bool result) {
	(result) ? cout << "\nYes : matrices are Typical" : cout << "\nNo : matrices are not Typical";
}
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	short arrSecond[3][3];
	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);

	FillMatrix(arrSecond, 3, 3);
	cout << "\nMatrix 2 :\n";
	PrintMatrix(arrSecond, 3, 3);

	PrintResult(IsMatrixTypical(arrFirst, arrSecond, 3, 3));

}
/*
output :
Matrix 1 :
 04      08      08
 06      09      01
 01      04      06

Matrix 2 :
 08      02      07
 04      10      01
 08      03      10

No : matrices are not Typical

*/