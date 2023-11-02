#include<iostream>
#include<iomanip>

using  namespace std;

void FillMatrix(short arr[3][3], short rows, short cols) {
	short number = 1;
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			arr[indexFirst][indexSec] = number;
			number++;
		}
	}
}
void PrintMatrix(short arr[3][3], short rows, short cols) {
	cout << "The following is a 3 * 3 ordered matrix is :\n";
	for (short indexFirst = 0; indexFirst < rows; indexFirst++) {
		for (short indexSec = 0; indexSec < cols; indexSec++) {
			cout << setw(3) << arr[indexFirst][indexSec] << "\t";
		}
		cout << endl;
	}
}
int main() {
	short arr[3][3];
	FillMatrix(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
}
/*
output :
The following is a 3 * 3 ordered matrix is :
  1       2       3
  4       5       6
  7       8       9

*/