#include <iostream>
#include <string>
using namespace std;

string readNumberFromUser(string message) {

	string pinCode;

	cout << message + "\n";
	cin >> pinCode;

	return pinCode;

}
bool login() {
	string forsure;
	do {
		forsure = readNumberFromUser("Please Enter a pin code\n");
		if (forsure == "1234") {
			return true;
		}
		else {
			cout << "\nwrong Pin\n";
			system("color 4F");
		}
	} while (forsure != "1234");





}
void printResult(bool result) {
	if (result) {
		system("color 2F");
		cout << "Your Balance is 75800 $";

	}

}

int main()
{
	printResult(login());
}/*
 Please Enter a pin code

ssss

wrong Pin
Please Enter a pin code

ssss

wrong Pin
Please Enter a pin code

1234
Your Balance is 75800 $*/