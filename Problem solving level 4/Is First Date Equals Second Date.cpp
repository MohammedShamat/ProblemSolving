#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<cstdio>
using  namespace std;

struct Date {
	short year;
	short month;
	short day;
};

short ReadYear(string message) {
	int number = 0;
	cout << message << endl;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}

short ReadMonth(string message) {
	int number = 0;
	cout << message << endl;
	cin >> number;
	while (cin.fail() || (number < 1 || number>12)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}

short ReadDay(string message) {
	int number = 0;
	cout << message << endl;
	cin >> number;
	while (cin.fail() || (number < 1 || number>31)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}

bool  IsFirstDateEqualsSecondDate(Date firstDate, Date secondDate) {
	return (firstDate.year == secondDate.year) ? ((firstDate.month == secondDate.month) ?
		((firstDate.day == secondDate.day) ? true : false) : false) : false;
}

int main() {
	Date firstDate;
	Date secondDate;
	firstDate.year = ReadYear("Enter a year?");
	firstDate.month = ReadMonth("Please Enter a month");
	firstDate.day = ReadDay("Please Enter A Day");
	secondDate.year = ReadYear("Enter a year?");
	secondDate.month = ReadMonth("Please Enter a month");
	secondDate.day = ReadDay("Please Enter A Day");
	IsFirstDateEqualsSecondDate(firstDate, secondDate) ? cout << "\nYes, Date1 is Equal  Date2" :
		cout << "\nNo, Date1 is NOT Equal  Date2";


}
/*
output
Enter a year?
2011
Please Enter a month
12
Please Enter A Day
12
Enter a year?
2011
Please Enter a month
10
Please Enter A Day
12

No, Date1 is NOT Equal  Date2

or
Enter a year?
2023
Please Enter a month
10
Please Enter A Day
24
Enter a year?
2023
Please Enter a month
10
Please Enter A Day
24

Yes, Date1 is Equal  Date2
*/