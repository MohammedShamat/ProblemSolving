#include <iostream>



using namespace std;


int readNumberFromUser() {
	int number;
	cout << "Please Enter a number\n";
	cin >> number;
	while (cin.fail() || number <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}
int readPowerFromUser() {
	int power;
	cout << "Please Enter a power number\n";
	cin >> power;
	while (cin.fail() || power <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> power;
	}
	return power;
}
int powerOfAnyNumber(int number, int power) {
	if (power == 0) {
		return 1;
	}
	int result = 1;
	for (int counter = 1; counter <= power; counter++) {
		result = result * number;
	}
	return result;
}

int main() {
	
	int number = readNumberFromUser();
	int power = readPowerFromUser();
	cout << powerOfAnyNumber(number, power) << endl;

	return 0;

}/*/
 output:
 Please Enter a number
fds
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
5
Please Enter a power number
5
3125

 */