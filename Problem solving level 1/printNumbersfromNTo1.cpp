#include <iostream>



using namespace std;


short readNumberFromUser() {
	short number;
	cout << "Please Enter range of numbers \n";
	cin >> number;
	while (cin.fail() || number <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}

void printNumbersfromNTo1(short number) {
	for (short counter = number; counter >= 1; counter--) {
		cout << "number is " << counter << endl;

	}
}

int main()
{
	printNumbersfromNTo1(readNumberFromUser());

	return 0;

}/*
 Please Enter range of numbers
12
number is 12
number is 11
number is 10
number is 9
number is 8
number is 7
number is 6
number is 5
number is 4
number is 3
number is 2
number is 1*/