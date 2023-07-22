#include <iostream>
#include <string>
using namespace std;


void readNumbersFromUsers(float& number1, float& number2) {

    cout << "Please Enter First number ...\n";
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

void SwapBetweenTwoNumbers(float& firstNum, float& secondNum) {
    float Temp = firstNum;
    firstNum = secondNum;
    secondNum = Temp;

}


void printResult(float firstNum, float secondNum) {
    cout << "*****************************\n";
    cout << "First Num is " << firstNum << endl;
    cout << "Second Num is " << secondNum << endl;
    cout << "*****************************\n";

}

int main()
{

    float firstNumber, SecondNumber;
    readNumbersFromUsers(firstNumber, SecondNumber);
    printResult(firstNumber, SecondNumber);

    SwapBetweenTwoNumbers(firstNumber, SecondNumber);
    cout << "After Swap\n";
    printResult(firstNumber, SecondNumber);
 

    return 0;

}/*

 Please Enter First number ...
aasa
Invalid Number, Enter a valid one
-12
Please Enter Second number ...
55.6
*****************************
First Num is -12
Second Num is 55.6
*****************************
After Swap
*****************************
First Num is 55.6
Second Num is -12
*****************************
 */