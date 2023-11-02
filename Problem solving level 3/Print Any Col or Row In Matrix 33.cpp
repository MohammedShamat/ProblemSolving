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
void PrintAnyRowInMatrix(short arr[3][3], short rows, short cols) {
	for (short indexFirst = rows; indexFirst <= rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			printf(" %0*d\t", 2, arr[rows - 1][indexSec]);
		}
		cout << endl;
	}
}
void PrintAnyColInMatrix(short arr[3][3], short rows, short cols) {
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = cols; indexSec <= cols; indexSec++) {
			printf(" %0*d\t", 2, arr[indexFirst][cols - 1]);
		}
	}
}
int main() {
	srand((unsigned)time(NULL));
	short arrFirst[3][3];
	FillMatrix(arrFirst, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arrFirst, 3, 3);
	cout << "Middle Row of Matrix1 :\n";
	PrintAnyRowInMatrix(arrFirst, 2, 3);
	cout << "Middle col of Matrix1 :\n";
	PrintAnyColInMatrix(arrFirst, 3, 2);

}
/*
output :
Matrix 1 :
 07      08      03
 04      01      02
 10      01      04
Middle Row of Matrix1 :
 04      01      02
Middle col of Matrix1 :
 08      01      01

*/