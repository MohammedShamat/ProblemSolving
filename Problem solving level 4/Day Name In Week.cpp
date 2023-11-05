#include<iostream>
#include<string>


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

short DayNumberInWeek(short year, short month, short day) {
	float a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short dayName = ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;
	return dayName;
}
string DayNameInWeek(short dayNumber) {
	string namesOfDays[7] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return namesOfDays[dayNumber];
}

int main() {
	short yearFromUser = ReadYear("Enter a year?");
	short monthFromUser = ReadMonth("Please Enter a Month");
	short dayFromUser = ReadDay("Please Enter a day");
	short dayNumber = DayNumberInWeek(yearFromUser, monthFromUser, dayFromUser);
	cout << "\nDate       :" << dayFromUser << "/" << monthFromUser << "/" << yearFromUser << endl;
	cout << "Day Order  :" << dayNumber + 1 << endl;
	cout << "Day Name   :" << DayNameInWeek(dayNumber);

}


/*
output

Enter a year?
1994
Please Enter a Month
1
Please Enter a day
21

Date       :21/1/1994
Day Order  :6
Day Name   :Friday
*/