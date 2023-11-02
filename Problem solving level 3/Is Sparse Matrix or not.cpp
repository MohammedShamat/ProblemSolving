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
bool IsSparseMatrix(short matrix[3][3], short rows, short cols) {
	short counterOfZero = 0;
	short countOfNumber = 0;
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			if (matrix[indexFirst][indexSec] == 0) {
				counterOfZero++;
			}
			else
				countOfNumber++;
		}
	}
	return (counterOfZero > countOfNumber);
}
void PrintResult(bool result) {
	(result) ? cout << "It is Sparse" : cout << "It is Not Sparse";
}
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	short spraseMatrix[3][3] = { {25,0,0},
		{0,25,0},{0,50,25} };
	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);
	PrintResult(IsSparseMatrix(arrFirst, 3, 3));

	cout << "\nMatrix 2 :\n";
	PrintMatrix(spraseMatrix, 3, 3);
	PrintResult(IsSparseMatrix(spraseMatrix, 3, 3));

}
/*
output :
Matrix 1 :
 48      15      16
 39      25      03
 13      09      31
It is Not Sparse
Matrix 2 :
 25      00      00
 00      25      00
 00      50      25
It is Sparse
*/