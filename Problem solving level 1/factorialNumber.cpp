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


	return number;
}
int factorial(int number) {
	int sum = 1;

	for (int counter = 1; counter <= number; counter++) {
		sum *= counter;
	}
	return sum;
}
int main()
{
	cout << "factorial is : " << factorial(readPositiveNumberFromUser());
	return 0;

}/*
 Please Enter a positive number
dds
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
5
factorial is : 120
*/