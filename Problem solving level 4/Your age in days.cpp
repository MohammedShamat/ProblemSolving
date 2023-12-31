#include<iostream>
#include<string>
#include<ctime>
#pragma warning (disable:4996)
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
	NowDate.month = now->tm_mon;
	NowDate.day = now->tm_mday;
	return NowDate;
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
bool  IsFirstDateBeforeSecondDate(Date firstDate, Date secondDate) {
	return (firstDate.year < secondDate.year) ? true : ((firstDate.year ==
		secondDate.year) ? (firstDate.month < secondDate.month ? true : (firstDate.month ==
			secondDate.month ? firstDate.day < secondDate.day : false)) : false);
}

int CalculateDifferenceBetweenTwoDates(Date firstDate, Date secondDate, bool includeEndDay = false) {

	int difference = 0;
	while (IsFirstDateBeforeSecondDate(firstDate, secondDate)) {
		difference++;
		firstDate = IncreaseDateByOneDay(firstDate);
	}

	return includeEndDay ? ++difference : difference;


}
int main() {
	Date firstDate = ReadDateFromUser("Please Enter Your Date of Birth");
	Date secondDate = GetDateNowFromSys();
	cout << "Your age in : " << CalculateDifferenceBetweenTwoDates(firstDate, secondDate, true) << " day(s)";

}
/*
output
Please Enter Your Date of Birth
Enter a year?
1994
Please Enter a month
1
Please Enter A Day
21
Your age in : 10842 day(s)
*/