#include<iostream>
using namespace std;
short readNumberFromUser() {
	short number = 0;
	cout << "How many numbers do you want to enter?" << endl;
	cin >> number;
	while (cin.fail()||number<=0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout << "Please Enter a valid value\n";
		cin >> number;
	}
	return number;
}
void readArrayData(int array1[100], short length) {


	
	for (int index = 0; index <= length - 1; index++) {
		cout << "please enter number" << index + 1 << endl;
		cin >> array1[index];
	}
}

void printData(int array1[100], short length) {

	for (int index = 0; index <= length - 1; index++) {
		cout << "number of index[" << index + 1 << "]= " << array1[index] << endl;
	}

}
int calculateSum(int array1[100], short length) {
	int sum = 0;
	for (int index = 0; index <= length - 1; index++) {
		sum += array1[index];
	}
	return sum;
}

int main() {
	short length = readNumberFromUser();
	int array1[100];
	readArrayData(array1, length);
	printData(array1, length);
	int sum = calculateSum(array1, length);
	cout << "Sum is\t" << sum << endl;
	cout << "This is length of array\t" << length << endl;
	cout << "AVG is\t" << (float)sum / length;

	return 0;
}/*
 output
 How many numbers do you want to enter?
dsf
Please Enter a valid value
sfs
Please Enter a valid value
-9
Please Enter a valid value
0
Please Enter a valid value
2
please enter number1
35
please enter number2
40
number of index[1]= 35
number of index[2]= 40
Sum is  75
This is length of array 2
AVG is  37.5
 
 */