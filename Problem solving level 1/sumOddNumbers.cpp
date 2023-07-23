#include <iostream>



using namespace std;

enum checkTypeOfNumber {
	Ood = 1, Even = 2
};
short readNumberFromUser() {
	short number;
	cout << "Please Enter a numbers \n";
	cin >> number;
	while (cin.fail() || number <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}

checkTypeOfNumber oddOrEven(short number) {
	if (number % 2 != 0) { return checkTypeOfNumber::Ood; }

	else
		return checkTypeOfNumber::Even;
}




short sumOddNumbers(short number) {
	short sum = 0;
	for (short counter = 1; counter <= number; counter++) {
		if (oddOrEven(counter) == checkTypeOfNumber::Ood) {
			sum += counter;
		}

	}
	return sum;
}

int main()
{
	cout << "Sum All odd nummbers is : " << sumOddNumbers(readNumberFromUser());

	return 0;

}/*
 Please Enter a numbers
dsx.
Invalid Number, Enter a valid one
5
Sum All odd nummbers is : 9
*/