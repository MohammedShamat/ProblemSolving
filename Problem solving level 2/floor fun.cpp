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
float myFloor(float number) {
	int numberInt = (int)number;
	if (numberInt == number) {
		return numberInt;
	}
	else if (number < 0) {
		return --numberInt;
	}

	else {
		if (number > 0)
			return numberInt;
	}



}


int main() {
	float number = readNumberFromUser("Please Enter number ?");

	cout << "My Floor Fun Result : " << myFloor(number);

}



/*
Please Enter number ?
dd
please enter a correct value
-10.3
My Floor Fun Result : -11
Please Enter number ?
10.6
My Floor Fun Result : 10
*/