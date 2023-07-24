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
	short counter = 3;
	do {
		counter--;
		forsure = readNumberFromUser("Please Enter A pin code\n");
		if (forsure == "1234") {
			return 1;
		}
		else {

			system("color 4F");
			cout << "\nwrong Pin you have " << counter << " more tries\n";
		}
	} while (forsure != "1234" && counter >= 1);


	return 0;


}
void printResult(bool result) {
	if (result) {
		system("color 2F");
		cout << "Your Balance is 75800 $";

	}
	else {
		cout << "\nYour card blocked you should to call to bank...\n";
	}

}

int main()
{
	printResult(login());
}/*
 
 Please Enter A pin code

sdsaad

wrong Pin you have 2 more tries
Please Enter A pin code

1684

wrong Pin you have 1 more tries
Please Enter A pin code

1234
Your Balance is 75800 $*/