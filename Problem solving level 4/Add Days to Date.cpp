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

short ReadAddDays(string message) {
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

bool IsLeapYear(short year) {
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}

short DaysInMonth(short year, short month) {

	short arr31Dyas[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return  (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arr31Dyas[month - 1];

}

short TotalDaysFromBeginningYear(short year, short month, short days) {
	short totalDays = 0;
	for (short counter = 1; counter <= month - 1; counter++) {
		totalDays += DaysInMonth(year, counter);
	}

	return (totalDays + days);

}

Date DateAfterAddedDays(Date date, short addsDays) {
	Date newDate = date;
	short totalDays = TotalDaysFromBeginningYear(newDate.year, newDate.month, newDate.day) + addsDays;
	short daysInMonth = 0;
	newDate.month = 1;
	while (true) {
		daysInMonth = DaysInMonth(newDate.year, newDate.month);
		if (totalDays > daysInMonth) {
			totalDays -= daysInMonth;
			newDate.month++;
			if (newDate.month > 12) {
				newDate.month = 1;
				newDate.year++;
			}

		}
		else {
			newDate.day = totalDays;
			break;
		}
	}
	return newDate;
}


int main() {
	Date date;
	Date dateAfterAdded;
	date.year = ReadYear("Enter a year?");
	date.month = ReadMonth("Please Enter a month");
	date.day = ReadDay("Please Enter A Day");
	short addsDaysFromUser = ReadAddDays("How many days to add ?");
	dateAfterAdded = DateAfterAddedDays(date, addsDaysFromUser);
	cout << "Date after added [" << addsDaysFromUser << "] days is : " << dateAfterAdded.day << "/" << dateAfterAdded.month << "/" << dateAfterAdded.year;
}


/*
output
Enter a year?
2022
Please Enter a month
10
Please Enter A Day
10
How many days to add ?
2500
Date after added [2500] days is : 14/8/2029

or

Enter a year?
2022
Please Enter a month
11
Please Enter A Day
10
How many days to add ?
150
Date after added [150] days is : 9/4/2023
*/