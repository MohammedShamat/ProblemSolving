#pragma warning (disable:4996)
#include<iostream>
#include<string>
#include<cstdio>
#include<ctime>

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

bool IsLastDayInMonth(Date date) {
	return DaysInMonth(date.year, date.month) == date.day;
}

bool IsLastMonthInYear(short month) {
	return month == 12;
}

short TotalDaysFromBeginningYear(short year, short month, short days) {
	short totalDays = 0;
	for (short counter = 1; counter <= month - 1; counter++) {
		totalDays += DaysInMonth(year, counter);
	}

	return (totalDays + days);

}

Date ReadDateFromUser(string message) {
	Date date;
	cout << message << endl;
	date.year = ReadYear("Enter a year?");
	date.month = ReadMonth("Please Enter a month");
	date.day = ReadDay("Please Enter A Day");
	return  date;
}
Date GetDateNowFromSys() {
	Date NowDate;
	time_t timeNow = time(0);
	tm* now = localtime(&timeNow);
	NowDate.year = now->tm_year + 1900;
	NowDate.month = now->tm_mon + 1;
	NowDate.day = now->tm_mday;
	return NowDate;
}
short DayNumberInWeek(short year, short month, short day) {
	float a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short dayName = ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;
	return dayName;
}
short DayNumberInWeek(Date date) {
	float a = (14 - date.month) / 12;
	short y = date.year - a;
	short m = date.month + (12 * a) - 2;
	short dayNumber = ((date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;
	return dayNumber;
}
string DayNameInWeek(short dayNumber) {
	string namesOfDays[7] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return namesOfDays[dayNumber];
}

bool IsEndOfWeek(Date date) {
	return(DayNumberInWeek(date) == 6);
}

bool IsWeekEnd(Date date) {
	return(DayNumberInWeek(date) == 6 || DayNumberInWeek(date) == 5);
}

bool IsBusinessDay(Date date) {
	return !(IsWeekEnd(date));
}

short DaysUntilTheEndOfWeek(Date date) {
	return (6 - DayNumberInWeek(date));
}
short DaysUntilTheEndOfMonth(Date date) {
	return  (DaysInMonth(date.year, date.month) - date.day);
}
short DaysUntilTheEndOfYear(Date date) {
	return  ((IsLeapYear(date.year) ? 366 : 365) - TotalDaysFromBeginningYear(date.year, date.month, date.day));
}

int main() {

	Date date = GetDateNowFromSys();

	cout << "Today is " << DayNameInWeek(DayNumberInWeek(date)) << " , "
		<< date.year << "/" << date.month << "/" << date.day << endl;
	cout << "\nIs it End of week?\n";
	IsEndOfWeek(date) ? cout << "Yes it is end of week.\n\n" : cout << "No not end of week.\n\n";
	cout << "\nIs it Weekend?\n";
	IsWeekEnd(date) ? cout << "Yes it is Weekend.\n\n" : cout << "No not Weekend.\n\n";
	cout << "\nIs it Business Day?\n";
	IsBusinessDay(date) ? cout << "Yes it is a Business Day.\n\n" : cout << "No not a Business Day.\n\n";
	cout << "Days Until End of Week is : " << DaysUntilTheEndOfWeek(date) << " Day(s)." << endl;
	cout << "Days Until End of Month is : " << DaysUntilTheEndOfMonth(date) << " Day(s)." << endl;
	cout << "Days Until End of Year is : " << DaysUntilTheEndOfYear(date) << " Day(s)." << endl;
}
/*
output

Today is Monday , 2023/10/30

Is it End of week?
No not end of week.


Is it Weekend?
No not Weekend.


Is it Business Day?
Yes it is a Business Day.

Days Until End of Week is : 6 Day(s).
Days Until End of Month is : 1 Day(s).
Days Until End of Year is : 62 Day(s).
*/