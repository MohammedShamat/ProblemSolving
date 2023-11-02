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
short SumMatrix(short arr[3][3], short rows, short cols) {
	short sumOfMatrix = 0;
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			sumOfMatrix += arr[indexFirst][indexSec];
		}

	}
	return sumOfMatrix;
}
bool IsMatrixEqual(short arrFirst[3][3], short arrSecond[3][3], short rows, short cols) {
	return (SumMatrix(arrFirst, 3, 3) == SumMatrix(arrSecond, 3, 3));
}
void PrintResult(bool result) {
	(result) ? cout << "\nYes : matrices are equal" : cout << "\nNo : matrices are not equal";
}
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	short arrSecond[3][3];
	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);
	cout << "Sum Of Matrix is = " << SumMatrix(arrFirst, 3, 3) << endl;
	FillMatrix(arrSecond, 3, 3);
	cout << "\nMatrix 2 :\n";
	PrintMatrix(arrSecond, 3, 3);
	cout << "Sum Of Matrix is = " << SumMatrix(arrSecond, 3, 3) << endl;
	PrintResult(IsMatrixEqual(arrFirst, arrSecond, 3, 3));

}
/*
output :
Matrix 1 :
 05      08      06
 06      02      02
 09      06      02
Sum Of Matrix is = 46

Matrix 2 :
 05      02      01
 01      09      05
 07      06      10
Sum Of Matrix is = 46

Yes : matrices are equal

or

Matrix 1 :
 10      01      05
 06      10      10
 05      10      07
Sum Of Matrix is = 64

Matrix 2 :
 02      08      10
 06      05      06
 02      10      09
Sum Of Matrix is = 58

No : matrices are not equal

*/