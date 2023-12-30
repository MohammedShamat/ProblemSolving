#include<iostream>
#include<string>

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
bool IsLeapYear(short year) {
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}
short DaysInMonth(short year, short month) {

	short arr31Dyas[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return  (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arr31Dyas[month - 1];

}

bool IsLastDayInMonth(short year, short month, short day) {
	return DaysInMonth(year, month) == day;
}
bool IsLastMonthInYear(short month) {
	return month == 12;
}

int main() {
	Date date;

	date.year = ReadYear("Enter a year?");
	date.month = ReadMonth("Please Enter a month");
	date.day = ReadDay("Please Enter A Day");
	IsLastDayInMonth(date.year, date.month, date.day) ? cout << "Yes, day is last day in month." :
		cout << "No, day is not last day in month.";
	IsLastMonthInYear(date.month) ? cout << "\nYes, month is last month in year." :
		cout << "\nNo, month is not last month in year.";
}
/*
output

Enter a year?
1955
Please Enter a month
5
Please Enter A Day
31
Yes, day is last day in month
No, month is not last month in year

or
Enter a year?
2023
Please Enter a month
12
Please Enter A Day
15
No, day is not last day in month
Yes, month is last month in year

or

Enter a year?
2033
Please Enter a month
12
Please Enter A Day
31
Yes, day is last day in month
Yes, month is last month in year
*/