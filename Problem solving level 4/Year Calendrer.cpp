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

short DayNumberInWeek(short year, short month, short day) {
	float a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short dayName = ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;
	return dayName;
}

string DayNameInWeek(short dayNumber) {
	string namesOfDays[7] = { "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return namesOfDays[dayNumber];
}

string NameOfMonth(short numMonth) {
	string arrMonthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May","Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return arrMonthNames[numMonth - 1];
}

void MonthCalender(short year, short month) {
	short dayInMonth = DaysInMonth(year, month);
	short dayNumber = DayNumberInWeek(year, month, 1);
	cout << "\n  ________________" << NameOfMonth(month) << "______________\n\n";
	cout << "  ";
	for (short index = 0; index < 7; index++) {
		cout << DayNameInWeek(index) << "  ";
	}
	cout << endl;

	int i;
	for (i = 0; i < dayNumber; i++)
		printf("     ");

	for (int j = 1; j <= dayInMonth; j++) {
		printf("%5d", j);
		if (++i == 7) {
			i = 0;
			printf("\n");
		}
	}

	cout << "\n  _________________________________\n\n";
}
void YearCalendrer(short year) {

	for (short counter = 1; counter <= 12; counter++) {
		MonthCalender(year, counter);
	}

}
int main() {
	short yearFromUser = ReadYear("Enter a year?");
	cout << "\n  _________________________________\n\n";
	cout << "\t  Calender - " << yearFromUser;
	cout << "\n  _________________________________\n\n";
	YearCalendrer(yearFromUser);




}


/*
output
Enter a year?
2023

  _________________________________

		  Calender - 2023
  _________________________________


  ________________Jan______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
	1    2    3    4    5    6    7
	8    9   10   11   12   13   14
   15   16   17   18   19   20   21
   22   23   24   25   26   27   28
   29   30   31
  _________________________________


  ________________Feb______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
				   1    2    3    4
	5    6    7    8    9   10   11
   12   13   14   15   16   17   18
   19   20   21   22   23   24   25
   26   27   28
  _________________________________

  ........etc

*/