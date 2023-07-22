#include <iostream>
#include <string>
using namespace std;


void readNumbersFromUsers(float& number1, float& number2) {

    cout << "Please Enter first number ...\n";
    cin >> number1;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> number1;
    }
    cout << "Please Enter Second number ...\n";
    cin >> number2;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> number2;
    }

}

float checkMaxOfTwoNumbers(float firstNum, float secondNum) {
    if (firstNum > secondNum) {
        return firstNum;
    }
    else {
        return secondNum;
    }


}

void printResult(float checkNum) {

    cout << "This Number is Bigger " << checkNum;

}

int main()
{

    float firstNumber, SecondNumber;
    readNumbersFromUsers(firstNumber, SecondNumber);
    printResult(checkMaxOfTwoNumbers(firstNumber, SecondNumber));
    return 0;

}/*
 output
 Please Enter first number ...
aada33
Invalid Number, Enter a valid one
-9
Please Enter Second number ...
-8
This Number is Bigger -8
*/