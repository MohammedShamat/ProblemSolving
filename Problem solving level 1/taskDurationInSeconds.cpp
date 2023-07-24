#include <iostream>
#include <string>
using namespace std;

struct taskDuration {
	float numberOfDays, numberOfHours, numberOfMinutes, numberOfseconds;
};

float readNumberFromUser(string message) {

	float number;

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

taskDuration readTaskDuration() {
	taskDuration taskDuration;
	taskDuration.numberOfDays = readNumberFromUser("Please Enter Number Of Days?");
	taskDuration.numberOfHours = readNumberFromUser("Please Enter Number Of Hours?");
	taskDuration.numberOfMinutes = readNumberFromUser("Please Enter Number Of Minutes?");
	taskDuration.numberOfseconds = readNumberFromUser("Please Enter Number Of Seconds?");

	return taskDuration;
}
float taskDurationInsecondes(taskDuration taskDuration) {
	float durationInSeconds = 0.0;
	durationInSeconds = taskDuration.numberOfDays * 24 * 60 * 60;
	durationInSeconds += taskDuration.numberOfHours * 60 * 60;
	durationInSeconds += taskDuration.numberOfMinutes * 60;
	durationInSeconds += taskDuration.numberOfseconds;
	return durationInSeconds;
}
void printResult(float taskDurationInsecondes) {
	cout << "Task Duration in seconds is = " << taskDurationInsecondes;
}
int main()
{

	printResult(taskDurationInsecondes(readTaskDuration()));
}/*
 
 Please Enter Number Of Days?
vvcds
Invalid Number, Enter a valid one
-12
Invalid Number, Enter a valid one
0
Please Enter Number Of Hours?
24
Please Enter Number Of Minutes?
56
Please Enter Number Of Seconds?
56
Task Duration in seconds is = 89816*/