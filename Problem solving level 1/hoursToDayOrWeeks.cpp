#include <iostream>
#include <string>
using namespace std;



float readNumberFromUser(string message) {

	float number;
	
		cout << message + "\n";
		cin >> number;
		while (cin.fail() || number <= 0) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one\n";
			cin >> number;
		}
	
	return number;

}
float hoursToDays(float numberOfHours) {
	float numbersOfDays = numberOfHours / 24;
	return  numbersOfDays;
}
float hoursToWeeks(float numbersOfhours) {
	float numberOfweeks = numbersOfhours / 24 / 7;
	return numberOfweeks;
}
float daysToWeek(float numberOfDays) {
	float dayOfWeek = numberOfDays / 7;
	return dayOfWeek;
}
void printResult(float result) {
	cout << result << endl;
}

int main()
{
	float numberOfHours = readNumberFromUser("Please Enter a Number of Hours ?");
	cout << "Hours to days : ";
	printResult(hoursToDays(numberOfHours));
	cout << "\nHours to Weeks : ";
	printResult(hoursToWeeks(numberOfHours));


}/*
 
 Please Enter a Number of Hours ?
gg
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
5123
Hours to days : 213.458

Hours to Weeks : 30.494*/