#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<cstdio>
using  namespace std;

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

short TotalDaysFromBeginningYear(short year, short month, short days) {
	short totalDays = 0;
	for (short counter = 1; counter <= month - 1; counter++) {
		totalDays += DaysInMonth(year, counter);
	}

	return (totalDays + days);

}
int main() {
	short yearFromUser = ReadYear("Enter a year?");
	short monthFromUser = ReadMonth("Please Enter a month");
	short dayFromUser = ReadDay("Please Enter A Day");
	cout << "\nNumber of days from the begining of the year is " << TotalDaysFromBeginningYear(yearFromUser, monthFromUser, dayFromUser);


}


/*
output
Enter a year?
2022
Please Enter a month
9
Please Enter A Day
20

Number of days from the begining of the year is 263

*/