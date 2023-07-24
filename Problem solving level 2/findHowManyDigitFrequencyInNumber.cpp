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

void findHowManyANumberFrequency(int number, short frequency) {

	int remainder = 0;

	short counter = 0;


	while (number > 0) {
		remainder = number % 10;

		number = number / 10;
		if (remainder == frequency) {
			counter++;
		}

	}

	cout << "Digits " << frequency << " frequency is " << counter << " times\n";//or return counter
}



int main() {

	int number = readNumberFromUser("Please enter a positive number");
	short frequencyNumber = readNumberFromUser("Please enter which number you search");
	findHowManyANumberFrequency(number, frequencyNumber);

}
/* output
Please enter a positive number
dss+
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
144584
Please enter which number you search
4
Digits 4 frequency is 3 times

 */