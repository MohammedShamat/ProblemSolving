#include <iostream>
#include <string>
using namespace std;
enum palindromeNumber {
	Palindrome = 1,
	NotPalindrome = 2,
};

int readNumberFromUser(string message) {
	int number;

	cout << message << endl;
	cin >> number;
	while (cin.fail() || number <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}


	return number;
}
int reversedANumber(int number) {

	int remainder = 0;
	int reverseNumber = 0;


	while (number > 0) {
		remainder = number % 10;

		number = number / 10;
		reverseNumber = reverseNumber * 10 + remainder;
	}
	return reverseNumber;

}
palindromeNumber isPalindromeNumber(int number) {

	if (reversedANumber(number) == number)
		return palindromeNumber::Palindrome;

	else
		return palindromeNumber::NotPalindrome;
}

void printResult(palindromeNumber result) {

	if (result == palindromeNumber::Palindrome) {
		cout << "Is Palindrome Number";
	}
	else {
		cout << "Is not Palindrome Number";
	}


}


int main() {
	printResult(isPalindromeNumber(readNumberFromUser("Please Enter a Positive number")));



}
/* output
Please Enter a Positive number
sd
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
125521
Is Palindrome Number

 */