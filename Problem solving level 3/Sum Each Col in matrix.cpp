#include<iostream>
#include<iomanip>
#include<cstdlib>
using  namespace std;
short RandomNumber(short from, short to) {
	return rand() % (to - from + 1) + from;
}
void FillMatrix(short arrOfMatrix[3][3], short rows, short cols) {
	for (short index1 = 0; index1 < rows; index1++) {
		for (short index2 = 0; index2 < cols; index2++) {
			arrOfMatrix[index1][index2] = RandomNumber(1, 100);
		}
	}
}
void PrintArrOfMatrix(short arrOfMatrix[3][3], short rows, short cols) {
	cout << "The Following is Array " << rows << " * " << cols << " random matrix" << endl;
	for (short index1 = 0; index1 < rows; index1++) {
		for (short index2 = 0; index2 < cols; index2++) {
			cout << setw(3) << arrOfMatrix[index1][index2] << "\t";
		}
		cout << endl;
	}
}
int SumEachCol(short arrOfMatrix[3][3], short rows, short cols) {
	int sumOfRow = 0;
	for (short index = 0; index < rows; index++) {

		sumOfRow += arrOfMatrix[index][cols];
	}
	return sumOfRow;
}
void PrintSumEachColsInArrOfMatrix(short arrOfMatrix[3][3], short rows, short cols) {
	cout << "\nThe following are the sum of each clo in the matrix every digit :\n";
	for (short index = 0; index < cols; index++) {
		cout << " Col " << index + 1 << " Sum = " << SumEachCol(arrOfMatrix, rows, index) << endl;
	}
}


int main() {
	srand((unsigned)time(NULL));
	short arrOfMatrix[3][3];
	
	FillMatrix(arrOfMatrix, 3, 3);
	PrintArrOfMatrix(arrOfMatrix, 3, 3);
	PrintSumEachColsInArrOfMatrix(arrOfMatrix, 3, 3);
	
}/*
 The Following is Array 3 * 3 random matrix
 19      25      92
 47      30      69
 44      87      35

The following are the sum of each clo in the matrix every digit :
 Col 1 Sum = 110
 Col 2 Sum = 142
 Col 3 Sum = 196

 */