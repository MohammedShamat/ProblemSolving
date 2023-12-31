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

Date SubtractingDateByOneDay(Date date) {
	Date dateAfterDay = date;
	if (date.month == 1 && date.day == 1) {
		dateAfterDay.year--;
		dateAfterDay.month = 12;
		dateAfterDay.day = DaysInMonth(dateAfterDay.year, dateAfterDay.month);
		return dateAfterDay;
	}
	else if (date.day == 1) {
		dateAfterDay.month--;
		dateAfterDay.day = DaysInMonth(dateAfterDay.year, dateAfterDay.month);
		return dateAfterDay;
	}
	else {
		dateAfterDay.day--;
		return dateAfterDay;
	}


}
short TotalDaysFromBeginningYear(short year, short month, short days) {
	short totalDays = 0;
	for (short counter = 1; counter <= month - 1; counter++) {
		totalDays += DaysInMonth(year, counter);
	}

	return (totalDays + days);

}

Date SubtractingDateByXDays(Date date, short subDays) {
	Date newDate = date;
	for (short counter = 0; counter < subDays; counter++) {
		newDate = SubtractingDateByOneDay(newDate);
	}
	return newDate;
}

Date SubtractingDateOneWeek(Date date) {
	Date newDate = date;
	for (short counter = 0; counter < 7; counter++) {
		newDate = SubtractingDateByOneDay(newDate);
	}

	return newDate;
}
Date SubtractingDateXWeeks(Date date, short Weeks) {
	Date newDate = date;
	for (short counter = 0; counter < Weeks; counter++) {
		newDate = SubtractingDateOneWeek(newDate);
	}

	return newDate;
}

Date SubtractingDateOneMonth(Date date) {
	Date newDate = date;
	if (date.month == 1) {
		newDate.month = 12;
		newDate.year--;
	}
	else {
		newDate.month--;
	}
	short numberOfDaysInMonth = DaysInMonth(newDate.year, newDate.month);
	if (newDate.day > numberOfDaysInMonth) {
		newDate.day = numberOfDaysInMonth;
	}
	return newDate;
}
Date SubtractingDateXMonths(Date date, short months) {
	Date newDate = date;
	for (short counter = 0; counter < months; counter++) {
		newDate = SubtractingDateOneMonth(newDate);
	}

	return newDate;
}

Date SubtractingDateOneYear(Date date) {
	Date newDate = date;
	newDate.year--;
	return newDate;
}

Date SubtractingDateXYears(Date date, short Years) {
	Date newDate = date;
	for (short counter = 0; counter < Years; counter++) {//or faster newDate.year-=Years;
		newDate = SubtractingDateOneYear(newDate);
	}

	return newDate;
}

Date SubtractingDateOneDecade(Date date) {
	Date newDate = date;
	newDate.year -= 10;
	return newDate;
}

Date SubtractingDateXDecade(Date date, short Years) {
	Date newDate = date;
	for (short counter = 0; counter < Years; counter++) {//or faster newDate.year-=Years;
		newDate = SubtractingDateOneDecade(newDate);
	}

	return newDate;
}

Date SubtractingDateOneCentury(Date date) {
	Date newDate = date;
	newDate.year -= 100;
	return newDate;
}
Date SubtractingDateOneMillennium(Date date) {
	Date newDate = date;
	newDate.year -= 1000;
	return newDate;
}

int main() {

	Date date;
	Date dateSubDay;
	Date dateSubXDays;
	Date dateSubOneWeek;
	Date dateSubXWeeks;
	Date dateSubOneMonth;
	Date dateSubXMonth;
	Date dateSubOneYear;
	Date dateSubXYear;
	Date dateSubOneDecade;
	Date dateSubXDecade;
	Date dateSubOneCentury;
	Date dateSubOneMillennium;

	date.year = ReadYear("Enter a year?");
	date.month = ReadMonth("Please Enter a month");
	date.day = ReadDay("Please Enter A Day");
	dateSubDay = SubtractingDateByOneDay(date);
	dateSubXDays = SubtractingDateByXDays(dateSubDay, 10);
	dateSubOneWeek = SubtractingDateOneWeek(dateSubXDays);
	dateSubXWeeks = SubtractingDateXWeeks(dateSubOneWeek, 10);
	dateSubOneMonth = SubtractingDateOneMonth(dateSubXWeeks);
	dateSubXMonth = SubtractingDateXMonths(dateSubOneMonth, 5);
	dateSubOneYear = SubtractingDateOneYear(dateSubXMonth);
	dateSubXYear = SubtractingDateXYears(dateSubOneYear, 10);
	dateSubOneDecade = SubtractingDateOneDecade(dateSubXYear);
	dateSubXDecade = SubtractingDateXDecade(dateSubOneDecade, 10);
	dateSubOneCentury = SubtractingDateOneCentury(dateSubXDecade);
	dateSubOneMillennium = SubtractingDateOneMillennium(dateSubOneCentury);
	cout << "\nDate After Subtracting : \n";
	cout << "\n1- Subtracting one day is : " << dateSubDay.day << "/" << dateSubDay.month << "/" << dateSubDay.year;
	cout << "\n2- Subtracting 10 day is : " << dateSubXDays.day << "/" << dateSubXDays.month << "/" << dateSubXDays.year;
	cout << "\n3- Subtracting one Week is : " << dateSubOneWeek.day << "/" << dateSubOneWeek.month << "/" << dateSubOneWeek.year;
	cout << "\n4- Subtracting 10 Weeks is : " << dateSubXWeeks.day << "/" << dateSubXWeeks.month << "/" << dateSubXWeeks.year;
	cout << "\n5- Subtracting One month is : " << dateSubOneMonth.day << "/" << dateSubOneMonth.month << "/" << dateSubOneMonth.year;
	cout << "\n6- Subtracting 5 month is : " << dateSubXMonth.day << "/" << dateSubXMonth.month << "/" << dateSubXMonth.year;
	cout << "\n7- Subtracting One Year is : " << dateSubOneYear.day << "/" << dateSubOneYear.month << "/" << dateSubOneYear.year;
	cout << "\n8- Subtracting 10 Years is : " << dateSubXYear.day << "/" << dateSubXYear.month << "/" << dateSubXYear.year;
	cout << "\n9- Subtracting 10 Years is (faster) : " << dateSubXYear.day << "/" << dateSubXYear.month << "/" << dateSubXYear.year;
	cout << "\n10- Subtracting One Decade is : " << dateSubOneDecade.day << "/" << dateSubOneDecade.month << "/" << dateSubOneDecade.year;
	cout << "\n11- Subtracting 10 Decade is : " << dateSubXDecade.day << "/" << dateSubXDecade.month << "/" << dateSubXDecade.year;
	cout << "\n12- Subtracting 10 Decade is (faster): " << dateSubXDecade.day << "/" << dateSubXDecade.month << "/" << dateSubXDecade.year;
	cout << "\n13- Subtracting One Century is : " << dateSubOneCentury.day << "/" << dateSubOneCentury.month << "/" << dateSubOneCentury.year;
	cout << "\n14- Subtracting One Millennium is : " << dateSubOneMillennium.day << "/" << dateSubOneMillennium.month << "/" << dateSubOneMillennium.year<<endl;




}
/*
output

Enter a year?
2022
Please Enter a month
12
Please Enter A Day
31

Date After Subtracting :

1- Subtracting one day is : 30/12/2022
2- Subtracting 10 day is : 20/12/2022
3- Subtracting one Week is : 13/12/2022
4- Subtracting 10 Weeks is : 4/10/2022
5- Subtracting One month is : 4/9/2022
6- Subtracting 5 month is : 4/4/2022
7- Subtracting One Year is : 4/4/2021
8- Subtracting 10 Years is : 4/4/2011
9- Subtracting 10 Years is (faster) : 4/4/2011
10- Subtracting One Decade is : 4/4/2001
11- Subtracting 10 Decade is : 4/4/1901
12- Subtracting 10 Decade is (faster): 4/4/1901
13- Subtracting One Century is : 4/4/1801
14- Subtracting One Millennium is : 4/4/801
*/