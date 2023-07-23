#include <iostream>



using namespace std;
//betweenAges18to25

short readAgeFromUser() {
	short age;
	cout << "Please Enter Your Age\n";
	cin >> age;
	while (cin.fail() || age <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> age;
	}
	return age;
}

bool validateNumberInRange(short number, short from, short to) {

	return(number >= from && number <= to);

}

void printResult(short age) {

	if (validateNumberInRange(age, 18, 25)) {
		cout << age << " is a valid age \n";
	}
	else
	{
		cout << age << " is invalid age \n";
	}
}

int main()
{

	printResult(readAgeFromUser());
	return 0;

}/*
 Please Enter Your Age
0
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
dss
Invalid Number, Enter a valid one
55
55 is invalid age
 */