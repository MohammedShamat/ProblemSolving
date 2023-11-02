#include<iostream>
#include<iomanip>
#include<cstdio>
#include <vector>
using  namespace std;
int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
	return number;
}
void FillMatrix(short matrix[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			matrix[indexFirst][indexSec] = randomNumberFun(1, 50);
		}
	}
}
void PrintMatrix(short matrix[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			printf(" %0*d\t", 2, matrix[indexFirst][indexSec]);
		}
		cout << endl;
	}
}
short MinNumberInMatrix(short matrix[3][3], short rows, short cols) {
	short minNumber = matrix[0][0];
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			(minNumber < matrix[indexFirst][indexSec]) ? minNumber = minNumber : minNumber = matrix[indexFirst][indexSec];
		}
	}
	return minNumber;
}
short MaxNumberInMatrix(short matrix[3][3], short rows, short cols) {
	short maxNumber = matrix[0][0];
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			(maxNumber > matrix[indexFirst][indexSec]) ? maxNumber = maxNumber : maxNumber = matrix[indexFirst][indexSec];
		}
	}
	return maxNumber;
}
void PrintResult(short matrix[3][3], short rows, short cols) {
	cout << "Minimum Number is : " << MinNumberInMatrix(matrix, rows, cols) << endl;
	cout << "Max Number is : " << MaxNumberInMatrix(matrix, rows, cols) << endl;
}
int main() {
	srand((unsigned)time(NULL));
	short firstMatrix[3][3];
	FillMatrix(firstMatrix, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(firstMatrix, 3, 3);
	PrintResult(firstMatrix, 3, 3);
}
/*
output :
Matrix 1 :
 43      25      11
 01      06      45
 32      41      02
Minimum Number is : 1
Max Number is : 45
*/