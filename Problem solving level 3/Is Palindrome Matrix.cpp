#include<iostream>
#include<iomanip>
#include<cstdio>
#include <vector>
using  namespace std;

int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
	return number;
}

void PrintMatrix(short matrix[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			printf(" %0*d\t", 2, matrix[indexFirst][indexSec]);
		}
		cout << endl;
	}
}

bool IsPalindromeMatrix(short matrix[3][3], short rows, short cols) {

	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols / 2; indexSec++) {
			if (matrix[indexFirst][indexSec] != matrix[indexFirst][cols - 1 - indexSec]) {
				return false;
			}
		}
	}
	return true;
}
void PrintResult(short matrix[3][3], short rows, short cols) {
	(IsPalindromeMatrix(matrix, rows, cols)) ? cout << "\nYes: Matrix is palindrome" : cout << "\nNo: Matrix is not palindrome";
}
int main() {
	srand((unsigned)time(NULL));
	short firstMatrix[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	cout << "Matrix 1 :\n";
	PrintMatrix(firstMatrix, 3, 3);
	PrintResult(firstMatrix, 3, 3);
	short SecondMatrix[3][3] = { {1,2,1},{5,5,5},{7,3,71} };
	cout << "\nMatrix 2 :\n";
	PrintMatrix(SecondMatrix, 3, 3);
	PrintResult(SecondMatrix, 3, 3);

}
/*
output :
Matrix 1 :
 01      02      01
 05      05      05
 07      03      07

Yes: Matrix is palindrome
Matrix 2 :
 01      02      01
 05      05      05
 07      03      71

No: Matrix is not palindrome
*/