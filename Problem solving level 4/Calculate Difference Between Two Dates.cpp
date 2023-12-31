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
	Date firstDate = ReadDateFromUser("First Date");
	Date secondDate = ReadDateFromUser("\nSecond Date");
	cout << "Difference is : " << CalculateDifferenceBetweenTwoDates(firstDate, secondDate) << " day(s).\n";
	cout << "Difference (Including end day) : " << CalculateDifferenceBetweenTwoDates(firstDate, secondDate, true) << " day(s)";

}
/*
output
First Date
Enter a year?
1950
Please Enter a month
1
Please Enter A Day
1

Second Date
Enter a year?
2022
Please Enter a month
1
Please Enter A Day
1
Difference is : 26298 day(s).
Difference (Including end day) : 26299 day(s)
*/