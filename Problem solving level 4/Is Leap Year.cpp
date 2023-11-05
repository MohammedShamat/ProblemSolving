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

bool IsLeapYear(short year) {

	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));

}
string PrintResult(bool IsLeapYear) {
	return IsLeapYear ? " is a leap year" : " is not a leap year";
}
int main() {
	short yearFromUser = ReadNumber("Enter a year?");
	cout << yearFromUser << PrintResult(IsLeapYear(yearFromUser));
}


/*
output
Enter a year?
2012
2012 is a leap year

or

Enter a year?
1971
1971 is not a leap year
*/