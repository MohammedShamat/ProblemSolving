#include <iostream>



using namespace std;


short readNumberFromUser() {
	short age;
	cout << "Please Enter a number between 18 and 25\n";
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

short readUntilAgeBetween(short from, short to) {
	short age = 0;
	do {
		age = readNumberFromUser();

	} while (!validateNumberInRange(age, from, to));
	return age;
}

void printResult(short age) {


	cout << age << " is a valid age \n";

}

int main()
{

	printResult(readUntilAgeBetween(18, 25));
	return 0;

}/*
 Please Enter a number between 18 and 25
26
Please Enter a number between 18 and 25
00
Invalid Number, Enter a valid one
dssd
Invalid Number, Enter a valid one
-0
Invalid Number, Enter a valid one
15
Please Enter a number between 18 and 25
22
22 is a valid age*/