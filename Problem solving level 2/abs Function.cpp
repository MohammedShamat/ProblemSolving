#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;


int readNumberFromUser(string message) {
	int number;

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
int myABS(int number) {
	if (number < 0) {
		return -1 * number;
	}
	else {
		return number;
	}

}


int main() {
	int number = readNumberFromUser("Please Enter a number ?");
	cout << "My abs Fun Result : " << myABS(number);


}



/*
Please Enter a number ?
sss
please enter a correct value
-99
My abs Fun Result : 99
*/