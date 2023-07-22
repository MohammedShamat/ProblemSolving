#include <iostream>
#include <string>
using namespace std;

float readNumberFromUser() {
    float number;
    cout << "Please Enter a number\n";
    cin >> number;
    while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout << "Please Enter a valid value\n";
		cin >> number;
	}
    return number;
}
float calculateHalfnumber(float number) {

    float halfNumber = number / 2;
    return halfNumber;

}

void printnumber(float number) {

    string result = "Half of " + to_string(number) + " is " + to_string(calculateHalfnumber(number));
    cout << result << endl;

}


int main()
{
    printnumber(readNumberFromUser());



    return 0;

}/*
 
 Please Enter a number
12.5
Half of 12.500000 is 6.250000

*/