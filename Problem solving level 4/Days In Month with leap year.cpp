#include<iostream>
#include<string>

using  namespace std;

short ReadNumber(string message) {
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

bool IsLeapYear(short year) {

	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));

}

short DaysInMonth(short year, short month) {

	short arr31Dyas[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return  (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arr31Dyas[month - 1];

}

short HoursInMonth(short year, short month) {
	return DaysInMonth(year, month) * 24;
}

int MinutesInMonth(short year, short month) {
	return HoursInMonth(year, month) * 60;
}
int SecondsInMonth(short year, short month) {
	return MinutesInMonth(year, month) * 60;
}

int main() {
	short yearFromUser = ReadNumber("Enter a year?");
	short monthFromUser = ReadMonth("Please Enter a Month To check");
	cout << "Number of Days in Month [" << monthFromUser << "] is " << DaysInMonth(yearFromUser, monthFromUser) << endl;
	cout << "Number of Hours in Month [" << monthFromUser << "] is " << HoursInMonth(yearFromUser, monthFromUser) << endl;
	cout << "Number of Minutes in Month [" << monthFromUser << "] is " << MinutesInMonth(yearFromUser, monthFromUser) << endl;
	cout << "Number of Seconds in Month [" << monthFromUser << "] is " << SecondsInMonth(yearFromUser, monthFromUser) << endl;
}


/*
output

Enter a year?
2000
Please Enter a Month To check
3
Number of Days in Month [3] is 31
Number of Hours in Month [3] is 744
Number of Minutes in Month [3] is 44640
Number of Seconds in Month [3] is 2678400
 or
Enter a year?
2000
Please Enter a Month To check
2
Number of Days in Month [2] is 29
Number of Hours in Month [2] is 696
Number of Minutes in Month [2] is 41760
Number of Seconds in Month [2] is 2505600
*/