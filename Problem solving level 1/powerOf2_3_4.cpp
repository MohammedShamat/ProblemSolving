#include <iostream>



using namespace std;


int readPositiveNumberFromUser() {
	int number;

	cout << "Please Enter a positive number\n";
	cin >> number;

	while (cin.fail() || number <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	cout << "**********************\n";
	return number;
}
void powerOf2_3_4(int number) {
	int powerOf2, powerOf3, powerOf4;
	powerOf2 = number * number;
	powerOf3 = powerOf2 * number;
	powerOf4 = powerOf3 * number;
	cout << powerOf2 << "\n" << powerOf3 << "\n" << powerOf4;
}

int main() {
	powerOf2_3_4(readPositiveNumberFromUser());
	return 0;

}/*
 output:
 Please Enter a positive number
vdd
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
3
**********************
9
27
81*/