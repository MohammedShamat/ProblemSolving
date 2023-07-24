#include <iostream>
#include <string>
using namespace std;

int readNumberFromUser(string message) {
	int number;

	cout << message << endl;
	cin >> number;
	while (cin.fail() || number <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}

	return number;
}

short findHowmanyANumberFrequency(int number, short frequency) {

	int remainder = 0;

	short counter = 0;


	while (number > 0) {
		remainder = number % 10;

		number = number / 10;
		if (remainder == frequency) {
			counter++;
		}

	}

	return counter;
}
void printAllDigitFrequncy(int number) {

	for (short count = 0; count <= 9; count++) {
		if (findHowmanyANumberFrequency(number, count) != 0) {
			cout << "digits " << count << " Frequncy is " << findHowmanyANumberFrequency(number, count) << " times" << endl;
		}

	}

}



int main() {



	printAllDigitFrequncy(readNumberFromUser("Please Enter a positive number"));

}
/* output
Please Enter a positive number
dxs
Invalid Number, Enter a valid one
145856966
digits 1 Frequncy is 1 times
digits 4 Frequncy is 1 times
digits 5 Frequncy is 2 times
digits 6 Frequncy is 3 times
digits 8 Frequncy is 1 times
digits 9 Frequncy is 1 times


 */