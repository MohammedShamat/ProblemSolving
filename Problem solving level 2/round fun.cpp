#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;


float readNumberFromUser(string message) {
	float number;

	cout << message << endl;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "please enter a correct value\n";
		cin >> number;

	}
	return number;
}
float myRound(float number) {
	int numberInt = number;
	if (number < 0) {
		if (numberInt > number && number > numberInt - 0.5) {
			return numberInt;
		}
		else if (numberInt - 0.5 >= number && number > numberInt - 1) {
			return --numberInt;
		}
		else {
			return number;
		}
	}
	else {

		if (numberInt < number && number <= numberInt + 0.5) {
			return numberInt;
		}
		else if (numberInt + 0.5 < number && number < numberInt + 1) {
			return ++numberInt;
		}
		else {
			return number;
		}

	}



}


int main() {
	float number = readNumberFromUser("Please Enter number of elements ?");

	cout << "My Round Fun Result : " << myRound(number);

}



/*
Please Enter number of elements ?
-10.3
My Round Fun Result : -10

Or
Please Enter number of elements ?
-10.7
My Round Fun Result : -11

Or

Please Enter number of elements ?
ddd
please enter a correct value
10.3
My Round Fun Result : 10

Or
Please Enter number of elements ?
10.7
My Round Fun Result : 11

Please Enter number of elements ?
-10.7
My Round Fun Result : -11
*/