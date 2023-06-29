#include <iostream>
#include <string>
using namespace std;

void readNumbersFromUsers(int& num1, int& num2, int& num3) {
    cout << "Please Enter first Number to sum them...\n";
    cin >> num1;
    cout << "Please Enter Second Number to sum them...\n";
    cin >> num2;
    cout << "Please Enter Third Number to sum them...\n";
    cin >> num3;
}

int sumOfNumbers(int num1, int num2, int num3) {
    int result = num1 + num2 + num3;
    return result;
}

void printSumOfNumbers(int numbers) {

    cout << "Sum Of number is = " << numbers;
}

int main()
{
    int num1, num2, num3;

    readNumbersFromUsers(num1, num2, num3);

    printSumOfNumbers(sumOfNumbers(num1, num2, num3));



    return 0;

}