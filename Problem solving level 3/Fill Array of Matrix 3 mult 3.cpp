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
			cout <<setw(3)<< arrOfMatrix[index1][index2] << "\t";
		}
		cout << endl;
	}
}
int main() {
	srand((unsigned)time(NULL));
	short arrOfMatrix[3][3];
	FillMatrix(arrOfMatrix, 3, 3);
	PrintArrOfMatrix(arrOfMatrix, 3, 3);
}/*
 The Following is Array 3*3 random matrix
  82      56      48
  61      37      61
  97      95      89

 */