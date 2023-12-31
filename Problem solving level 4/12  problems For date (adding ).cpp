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
short TotalDaysFromBeginningYear(short year, short month, short days) {
	short totalDays = 0;
	for (short counter = 1; counter <= month - 1; counter++) {
		totalDays += DaysInMonth(year, counter);
	}

	return (totalDays + days);

}

Date IncreaseDateByXDays(Date date, short addsDays) {
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

Date IncreaseDateOneWeek(Date date) {
	Date newDate = date;
	short totalDays = TotalDaysFromBeginningYear(newDate.year, newDate.month, newDate.day) + 7;
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
Date IncreaseDateXWeeks(Date date, short Weeks) {
	Date newDate = date;
	for (short counter = 0; counter < Weeks; counter++) {
		newDate = IncreaseDateOneWeek(newDate);
	}

	return newDate;
}

Date IncreaseDateOneMonth(Date date) {
	Date newDate = date;
	if (newDate.month == 12) {
		newDate.month = 1;
		newDate.year++;
	}
	else {
		newDate.month++;
	}
	short numberOfDaysInMonth = DaysInMonth(date.year, date.month);
	if (date.day > numberOfDaysInMonth) {
		date.day = numberOfDaysInMonth;
	}
	return newDate;
}
Date IncreaseDateXMonths(Date date, short months) {
	Date newDate = date;
	for (short counter = 0; counter < months; counter++) {
		newDate = IncreaseDateOneMonth(newDate);
	}

	return newDate;
}

Date IncreaseDateOneYear(Date date) {
	Date newDate = date;
	newDate.year++;
	return newDate;
}

Date IncreaseDateXYears(Date date, short Years) {
	Date newDate = date;
	for (short counter = 0; counter < Years; counter++) {//or faster newDate.year+=Years;
		newDate = IncreaseDateOneYear(newDate);
	}

	return newDate;
}

Date IncreaseDateOneDecade(Date date) {
	Date newDate = date;
	newDate.year += 10;
	return newDate;
}

Date IncreaseDateXDecade(Date date, short Years) {
	Date newDate = date;
	for (short counter = 0; counter < Years; counter++) {//or faster newDate.year+=Years;
		newDate = IncreaseDateOneDecade(newDate);
	}

	return newDate;
}

Date IncreaseDateOneCentury(Date date) {
	Date newDate = date;
	newDate.year += 100;
	return newDate;
}
Date IncreaseDateOneMillennium(Date date) {
	Date newDate = date;
	newDate.year += 1000;
	return newDate;
}

int main() {
	Date date;
	Date dateAfterDay;
	Date dateAfterXdays;
	Date dateAfterAddedOneWeek;
	Date dateAfterAddedXWeeks;
	Date dateAfterAddedOneMonth;
	Date dateAfterAddedXMonth;
	Date dateAfterAddedOneYear;
	Date dateAfterAddedOXYear;
	Date dateAfterAddedOneDecade;
	Date dateAfterAddedXDecade;
	Date dateAfterAddedOneCentury;
	Date dateAfterAddedOneMillennium;
	date.year = ReadYear("Enter a year?");
	date.month = ReadMonth("Please Enter a month");
	date.day = ReadDay("Please Enter A Day");
	dateAfterDay = IncreaseDateByOneDay(date);
	dateAfterXdays = IncreaseDateByXDays(dateAfterDay, 10);
	dateAfterAddedOneWeek = IncreaseDateOneWeek(dateAfterXdays);
	dateAfterAddedXWeeks = IncreaseDateXWeeks(dateAfterAddedOneWeek, 10);
	dateAfterAddedOneMonth = IncreaseDateOneMonth(dateAfterAddedXWeeks);
	dateAfterAddedXMonth = IncreaseDateXMonths(dateAfterAddedOneMonth, 5);
	dateAfterAddedOneYear = IncreaseDateOneYear(dateAfterAddedXMonth);
	dateAfterAddedOXYear = IncreaseDateXYears(dateAfterAddedOneYear, 10);
	dateAfterAddedOneDecade = IncreaseDateOneDecade(dateAfterAddedOXYear);
	dateAfterAddedXDecade = IncreaseDateXDecade(dateAfterAddedOneDecade, 10);
	dateAfterAddedOneCentury = IncreaseDateOneCentury(dateAfterAddedXDecade);
	dateAfterAddedOneMillennium = IncreaseDateOneMillennium(dateAfterAddedOneCentury);
	cout << "\nDate After adding : \n";
	cout << "\n1- Adding one day is : " << dateAfterDay.day << "/" << dateAfterDay.month << "/" << dateAfterDay.year;
	cout << "\n2- Adding 10 day is : " << dateAfterXdays.day << "/" << dateAfterXdays.month << "/" << dateAfterXdays.year;
	cout << "\n3- Adding one Week is : " << dateAfterAddedOneWeek.day << "/" << dateAfterAddedOneWeek.month << "/" << dateAfterAddedOneWeek.year;
	cout << "\n4- Adding 10 Weeks is : " << dateAfterAddedXWeeks.day << "/" << dateAfterAddedXWeeks.month << "/" << dateAfterAddedXWeeks.year;
	cout << "\n5- Adding One month is : " << dateAfterAddedOneMonth.day << "/" << dateAfterAddedOneMonth.month << "/" << dateAfterAddedOneMonth.year;
	cout << "\n6- Adding 5 month is : " << dateAfterAddedXMonth.day << "/" << dateAfterAddedXMonth.month << "/" << dateAfterAddedXMonth.year;
	cout << "\n7- Adding One Year is : " << dateAfterAddedOneYear.day << "/" << dateAfterAddedOneYear.month << "/" << dateAfterAddedOneYear.year;
	cout << "\n8- Adding 10 Years is : " << dateAfterAddedOXYear.day << "/" << dateAfterAddedOXYear.month << "/" << dateAfterAddedOXYear.year;
	cout << "\n9- Adding 10 Years is (faster) : " << dateAfterAddedOXYear.day << "/" << dateAfterAddedOXYear.month << "/" << dateAfterAddedOXYear.year;
	cout << "\n10- Adding One Decade is : " << dateAfterAddedOneDecade.day << "/" << dateAfterAddedOneDecade.month << "/" << dateAfterAddedOneDecade.year;
	cout << "\n11- Adding 10 Decade is : " << dateAfterAddedXDecade.day << "/" << dateAfterAddedXDecade.month << "/" << dateAfterAddedXDecade.year;
	cout << "\n12- Adding 10 Decade is (faster): " << dateAfterAddedXDecade.day << "/" << dateAfterAddedXDecade.month << "/" << dateAfterAddedXDecade.year;
	cout << "\n13- Adding One Century is : " << dateAfterAddedOneCentury.day << "/" << dateAfterAddedOneCentury.month << "/" << dateAfterAddedOneCentury.year;
	cout << "\n14- Adding One Millennium is : " << dateAfterAddedOneMillennium.day << "/" << dateAfterAddedOneMillennium.month << "/" << dateAfterAddedOneMillennium.year;




}
/*
output

Enter a year?
2022
Please Enter a month
12
Please Enter A Day
31

Date After adding :

1- Adding one day is : 1/1/2023
2- Adding 10 day is : 11/1/2023
3- Adding one Week is : 18/1/2023
4- Adding 10 Weeks is : 29/3/2023
5- Adding One month is : 29/4/2023
6- Adding 5 month is : 29/9/2023
7- Adding One Year is : 29/9/2024
8- Adding 10 Years is : 29/9/2034
9- Adding 10 Years is (faster) : 29/9/2034
10- Adding One Decade is : 29/9/2044
11- Adding 10 Decade is : 29/9/2144
12- Adding 10 Decade is (faster): 29/9/2144
13- Adding One Century is : 29/9/2244
14- Adding One Millennium is : 29/9/3244
*/