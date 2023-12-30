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
Date IncreaseDateByOneDay(Date date) {
	Date dateAfterDay = date;
	if (IsLastDayInMonth(date.year, date.month, date.day)) {
		if (IsLastMonthInYear(date.month)) {
			dateAfterDay.year++;
			dateAfterDay.month = 1;
			dateAfterDay.day = 1;
		}
		else {
			dateAfterDay.month++;
			dateAfterDay.day = 1;
		}

	}
	else {
		dateAfterDay.day++;
	}
	return dateAfterDay;

}
int main() {
	Date date;
	Date dateAfterDay;
	date.year = ReadYear("Enter a year?");
	date.month = ReadMonth("Please Enter a month");
	date.day = ReadDay("Please Enter A Day");
	dateAfterDay = IncreaseDateByOneDay(date);
	cout << "\n" << dateAfterDay.day << "/" << dateAfterDay.month << "/" << dateAfterDay.year;
}
/*
output

Enter a year?
2022
Please Enter a month
12
Please Enter A Day
30

31/12/2022

or
Enter a year?
2022
Please Enter a month
12
Please Enter A Day
31

1/1/2023
or
Enter a year?
2000
Please Enter a month
2
Please Enter A Day
28

29/2/2000
*/