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
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);
	cout << "Sum Of Matrix is = " << SumMatrix(arrFirst, 3, 3);

}
/*
output :
Matrix 1 :
 05      08      05
 05      03      07
 10      02      02
Sum Of Matrix is = 47

*/