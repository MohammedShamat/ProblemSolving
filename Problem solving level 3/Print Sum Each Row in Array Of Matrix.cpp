
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
int SumEachRow(short arrOfMatrix[3][3], short rows, short cols) {
	int sumOfRow = 0;
	for (short index = 0; index < cols; index++) {
		
		sumOfRow += arrOfMatrix[rows][index];
	}
	return sumOfRow;
}
void PrintSumEachRowInArrOfMatrix(short arrOfMatrix[3][3], short rows, short cols) {
	cout << "\nThe following are the sum of each row in the matrix :\n";
	for (short index = 0; index < rows; index++) {
		cout << " Row " << index + 1 << " Sum = " << SumEachRow(arrOfMatrix, index, cols) << endl;
	}
}
int main() {
	srand((unsigned)time(NULL));
	short arrOfMatrix[3][3];
	FillMatrix(arrOfMatrix, 3, 3);
	PrintArrOfMatrix(arrOfMatrix, 3, 3);
	PrintSumEachRowInArrOfMatrix(arrOfMatrix, 3, 3);
}/*
 The Following is Array 3 * 3 random matrix
 12      21      59
 26       7      35
 11      45      47

The following are the sum of each row in the matrix :
 Row 1 Sum = 92
 Row 2 Sum = 68
 Row 3 Sum = 103

 */