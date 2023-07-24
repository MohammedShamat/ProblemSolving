#include <iostream>
#include <string>
using namespace std;

enum monthOfYear {
	January = 1, February = 2, Macrh = 3, April = 4, May = 5, June = 6, July = 7, Ausgust = 8, September = 9, October = 10, November = 11, December = 12
};

short readNumberFromUserWithRange(string message, int from, int to) {

	short number;
	

		cout << message + "\n";
		cin >> number;
		while (cin.fail() || (number <= from || number > to)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one\n";
			cin >> number;
		}
	
	return number;

}

monthOfYear monthInYear(short numberOfMonth) {

	return (monthOfYear)numberOfMonth;

}
string getMonthOfYear(monthOfYear monthInYear) {
	switch (monthInYear)
	{
	case monthOfYear::January:
		return "The month is January";
	case monthOfYear::February:
		return "The month is February";
	case monthOfYear::Macrh:
		return "The month is Macrh";
	case monthOfYear::April:
		return "The month is April";
	case monthOfYear::May:
		return "The month is May";
	case monthOfYear::June:
		return "The year is June";
	case monthOfYear::July:
		return "The month is July";
	case monthOfYear::Ausgust:
		return "The month is Ausgust";
	case monthOfYear::September:
		return "The month is September";
	case monthOfYear::October:
		return "The month is October";
	case monthOfYear::November:
		return "The month is November";
	case monthOfYear::December:
		return "The month is December";
	}
}



int main()
{
	cout << getMonthOfYear(monthInYear(readNumberFromUserWithRange("Please Enter A number Of Month\n January=1,February=2,Macrh=3,April=4,May=5,June=6,July=7,Ausgust=8,September=9,October=10,November=11,December=12\n", 0, 12)));
}/*
 
 Please Enter A number Of Month
 January=1,February=2,Macrh=3,April=4,May=5,June=6,July=7,Ausgust=8,September=9,October=10,November=11,December=12

ddds
Invalid Number, Enter a valid one
15
Invalid Number, Enter a valid one
11
The month is November*/