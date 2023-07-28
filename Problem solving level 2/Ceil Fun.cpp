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
float myCeil(float number) {
	int numberInt = (int)number;
	if (number < 0) {
		return numberInt;
	}
	else {

		if (numberInt == number) {
			return number;
		}
		else if (number > 0)
			return ++numberInt;
	}



}


int main() {
	float number = readNumberFromUser("Please Enter number ?");

	cout << "My Ceil Fun Result : " << myCeil(number);

}



/*
* output
Please Enter number ?
10.7
My Ceil Fun Result : 11
or
Please Enter number ?
10
My Ceil Fun Result : 10
or
Please Enter number ?
-10.7
My Ceil Fun Result : -10
or
Please Enter number ?
-10.3
My Ceil Fun Result : -10
*/