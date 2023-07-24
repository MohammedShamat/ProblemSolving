#include <iostream>
#include <string>
using namespace std;

struct taskDuration {
	float numberOfDays, numberOfHours, numberOfMinutes, numberOfseconds;
};

int readNumberFromUser(string message) {

	int number;

	cout << message + "\n";
	cin >> number;
	while (cin.fail() || number < 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;

}
taskDuration secondsToDaysAndHoursAndMinutes(int totalSeconds) {

	taskDuration secondsToDuration;
	const int secondsPerDay = 24 * 60 * 60;
	const int secondsPerHours = 60 * 60;
	const int secondsPerMinutes = 60;
	int remainder = 0.0;

	secondsToDuration.numberOfDays = floor(totalSeconds / secondsPerDay);
	remainder = totalSeconds % secondsPerDay;
	secondsToDuration.numberOfHours = floor(remainder / secondsPerHours);
	remainder = remainder % secondsPerHours;
	secondsToDuration.numberOfMinutes = floor(remainder / secondsPerMinutes);
	remainder = remainder % secondsPerMinutes;
	secondsToDuration.numberOfseconds = remainder;
	return secondsToDuration;
}


void printResult(taskDuration secondsToDuration) {
	cout << "Day" << " : " << "Hours" << " : " << "Minutes" << " : " << "seconds\n";
	cout << secondsToDuration.numberOfDays << " : " <<
		secondsToDuration.numberOfHours << " : " <<
		secondsToDuration.numberOfMinutes << " : " << secondsToDuration.numberOfseconds;
}
int main()
{
	
	printResult(secondsToDaysAndHoursAndMinutes(readNumberFromUser("Please Enter Number Of Seconds")));
}/*
 Please Enter Number Of Seconds
bfcvfc
Invalid Number, Enter a valid one
-98
Invalid Number, Enter a valid one
15700
Day : Hours : Minutes : seconds
0 : 4 : 21 : 40
 */