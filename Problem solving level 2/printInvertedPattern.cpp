#include <iostream>
#include <string>
using namespace std;

int readNumberFromUser(string message) {
	int number;
	
	cout << message << endl;
	cin >> number;
	while (cin.fail() || (number<=0)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;


	}
	return number;
}

void printInvertedPattern(int number) {
	cout << "Inverted Pattern is\n";
	for (number; 0 < number; number--) {
		for (int counter = number; 0 < counter; counter--) {
			cout << number;
		}
		cout << endl;
	}

}





int main() {
	printInvertedPattern(readNumberFromUser("Please Enter a number"));
}/*
 output
 Please Enter a number
-99
Invalid Number, Enter a valid one
ddfs
Invalid Number, Enter a valid one
10
Inverted Pattern is
10101010101010101010
999999999
88888888
7777777
666666
55555
4444
333
22
1
 */