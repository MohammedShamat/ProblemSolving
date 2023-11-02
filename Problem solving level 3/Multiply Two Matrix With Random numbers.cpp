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
void MultiplyTwoMatrix(short arrFirst[3][3], short arrSecond[3][3], short MultiplyTwoMatrix[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			MultiplyTwoMatrix[indexFirst][indexSec] = arrFirst[indexFirst][indexSec] * arrSecond[indexFirst][indexSec];
		}

	}

}
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	short arrSecond[3][3];
	short MultiplyMatrix[3][3];

	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);
	FillMatrix(arrSecond, 3, 3);
	cout << "\nMatrix 2 :\n";
	PrintMatrix(arrSecond, 3, 3);
	cout << "\nMultiply Two Matrix :\n";
	MultiplyTwoMatrix(arrFirst, arrSecond, MultiplyMatrix, 3, 3);
	PrintMatrix(MultiplyMatrix, 3, 3);

}
/*
output :
Matrix 1 :
 04      10      06
 08      08      10
 02      04      09

Matrix 2 :
 07      03      10
 10      10      05
 01      05      09

Multiply Two Matrix :
 28      30      60
 80      80      50
 02      20      81

*/