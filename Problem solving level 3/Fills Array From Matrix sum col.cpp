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
void FillsArrayFromMatrix(short arrOfMatrix[3][3], short arrOne[3], short cols) {

	for (short index = 0; index < cols; index++) {
		arrOne[index] = SumEachCol(arrOfMatrix, cols, index);
	}
}
void printTheArray(short arr[3], short length) {
	cout << "\nThe following are the sum of each col in the matrix in other array :\n";
	for (int index = 0; index < length; index++) {
		cout << " Col " << index + 1 << " Sum = " << arr[index] << " " << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	short arrOfMatrix[3][3];
	short arr[3];
	FillMatrix(arrOfMatrix, 3, 3);
	PrintArrOfMatrix(arrOfMatrix, 3, 3);
	PrintSumEachColsInArrOfMatrix(arrOfMatrix, 3, 3);
	FillsArrayFromMatrix(arrOfMatrix,arr,3);
	printTheArray(arr,3);
}/*
 The Following is Array 3 * 3 random matrix
 80      16      90
 30      99      30
 12      26      16

The following are the sum of each clo in the matrix every digit :
 Col 1 Sum = 122
 Col 2 Sum = 141
 Col 3 Sum = 136

The following are the sum of each col in the matrix in other array :
 Col 1 Sum = 122
 Col 2 Sum = 141
 Col 3 Sum = 136


 */