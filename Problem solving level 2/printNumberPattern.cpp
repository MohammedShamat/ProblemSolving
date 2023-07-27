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
void printNumberPattern(int number) {
	cout << "Number Pattern is\n";
	for (int temp = 1; temp <= number; temp++) {
		for (int counter = 1; counter <= temp; counter++) {
			cout << temp;
		}
		cout << endl;
	}

}





int main() {
	printNumberPattern(readNumberFromUser("Please Enter a number"));
}/*

Please Enter a number
-99
Invalid Number, Enter a valid one
sss
Invalid Number, Enter a valid one
10
Number Pattern is
1
22
333
4444
55555
666666
7777777
88888888
999999999
10101010101010101010

 */