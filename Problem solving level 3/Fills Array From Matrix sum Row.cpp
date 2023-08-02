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
	cout << "\nThe following are the sum of each row in the matrix every digit :\n";
	for (short index = 0; index < rows; index++) {
		cout << " Row " << index + 1 << " Sum = " << SumEachRow(arrOfMatrix, index, cols) << endl;
	}
}
void FillsArrayFromMatrix(short arrOfMatrix[3][3], short arrOne[3], short cols) {

	for (short index = 0; index < 3; index++) {
		arrOne[index] = SumEachRow(arrOfMatrix, index, cols);
	}
}
void printTheArray(short arr[3], short length) {
	cout << "\nThe following are the sum of each row in the matrix in other array :\n";
	for (int index = 0; index < length; index++) {
		cout << " Row " << index + 1 << " Sum = " << arr[index] << " "<<endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	short arrOfMatrix[3][3];
	short arrOne[3];
	FillMatrix(arrOfMatrix, 3, 3);
	PrintArrOfMatrix(arrOfMatrix, 3, 3);
	PrintSumEachRowInArrOfMatrix(arrOfMatrix, 3, 3);
	FillsArrayFromMatrix(arrOfMatrix, arrOne, 3);
	printTheArray(arrOne, 3);
}/*
 The Following is Array 3 * 3 random matrix
 43      70      34
 32      57      60
 17      89      38

The following are the sum of each row in the matrix every digit :
 Row 1 Sum = 147
 Row 2 Sum = 149
 Row 3 Sum = 144

The following are the sum of each row in the matrix in other array :
 Row 1 Sum = 147
 Row 2 Sum = 149
 Row 3 Sum = 144

 */