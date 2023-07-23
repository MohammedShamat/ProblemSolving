#include <iostream>
#include <string>
using namespace std;

float readNumberFromUser(string message) {
	float number = 0.0;
	cout << message << "\n";
	cin >> number;
	while (cin.fail() ) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}

float sumNumbers() {
	float sum = 0.0;
	float number = 0.0;
	short counter = 1;

	do {
		number = readNumberFromUser("Please Enter a number " + to_string(counter));
		if (number == -99) {
			break;
		}
		sum += number;
		counter++;

	} while (number != -99);

	return sum;

}


int main()
{
	cout <<"Sum of All numbmers is : " << sumNumbers();

}/*
 
 Please Enter a number 1
fsfd
Invalid Number, Enter a valid one
55
Please Enter a number 2
635
Please Enter a number 3
1523
Please Enter a number 4
-99
Sum of All numbmers is : 2213
 */