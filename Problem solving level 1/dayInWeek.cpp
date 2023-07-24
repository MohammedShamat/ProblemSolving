#include <iostream>
#include <string>
using namespace std;

enum dayOfWeek {
	Saturday = 1, Sunday = 2, Monday = 3, Tuesday = 4, Wednesday = 5, Thursday = 6, Friday = 7
};

short readNumberFromUserWithRange(string message, int from, int to) {

	short number;


	cout << message + "\n";
	cin >> number;
	while (cin.fail() || (number <= from || number > to)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}

	return number;

}

dayOfWeek dayInWeek(short numberOfDay) {

	return (dayOfWeek)numberOfDay;

}
string getDayOfWeek(dayOfWeek dayInWeek) {
	switch (dayInWeek)
	{
	case dayOfWeek::Saturday:
		return "The day is Saturday";
	case dayOfWeek::Sunday:
		return "The day is Sunday";
	case dayOfWeek::Monday:
		return "The day is Monday";
	case dayOfWeek::Tuesday:
		return "The day is Tuesday";
	case dayOfWeek::Wednesday:
		return "The day is Wednesday";
	case dayOfWeek::Thursday:
		return "The day is Thursday";
	case dayOfWeek::Friday:
		return "The day is Friday";
	default:
		return "The day is Wrong day";
	}
}



int main()
{
	cout << getDayOfWeek(dayInWeek(readNumberFromUserWithRange("Please Enter A number Of Day Saturday=1,Sunday=2,Monday=3,Tuesday=4,Wednesday=5,Thursday=6,Friday=7", 0, 7)));
}/*
 
 Please Enter A number Of Day Saturday=1,Sunday=2,Monday=3,Tuesday=4,Wednesday=5,Thursday=6,Friday=7
faaf
Invalid Number, Enter a valid one
8
Invalid Number, Enter a valid one
6
The day is Thursday*/