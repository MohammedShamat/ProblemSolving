#include<iostream>
#include<string>
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

Date ReadDateFromUser(string message) {
	Date date;
	cout << message << endl;
	date.year = ReadYear("Enter a year?");
	date.month = ReadMonth("Please Enter a month");
	date.day = ReadDay("Please Enter A Day");
	return  date;
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



Date IncreaseDateByOneDay(Date date) {
	Date dateAfterDay = date;
	if (IsLastDayInMonth(date)) {
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
short ActucalVacationDays(Date vacationStarts, Date vacationEnds) {
	short daysCount = 0;
	int difference = CalculateDifferenceBetweenTwoDates(vacationStarts, vacationEnds);

	for (short count = 0; count < difference; count++) {

		if (!IsWeekEnd(vacationStarts)) {//isdatebeforedate2
			daysCount++;
		}
		vacationStarts = IncreaseDateByOneDay(vacationStarts);

	}
	return daysCount;
}
int main() {

	Date vacationStarts = ReadDateFromUser("Vacation Starts :\n");
	Date vacationEnds = ReadDateFromUser("Vacation Ends :\n");
	cout << "Vacation from : " << DayNameInWeek(DayNumberInWeek(vacationStarts)) << " , " << vacationStarts.day <<
		"/" << vacationStarts.month << "/" << vacationStarts.year << endl;
	cout << "Vacation To   : " << DayNameInWeek(DayNumberInWeek(vacationEnds)) << " , " << vacationEnds.day <<
		"/" << vacationEnds.month << "/" << vacationEnds.year << endl;
	cout << "Actucal Vacation Days is : " << ActucalVacationDays(vacationStarts, vacationEnds);
}
/*
output

Vacation Starts :

Enter a year?
2022
Please Enter a month
1
Please Enter A Day
1
Vacation Ends :

Enter a year?
2022
Please Enter a month
2
Please Enter A Day
2
Vacation from : Saturday , 1/1/2022
Vacation To   : Wednesday , 2/2/2022
Actucal Vacation Days is : 23
*/