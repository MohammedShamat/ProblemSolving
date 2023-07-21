#include <iostream>
#include <string>
using namespace std;

short readNumberFromUser() {

    short number;
    cout << "Please enter a number\n";
    cin >> number;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a vaild value\n";
        cin >> number;
    }
    return number;
}

enum enCheckTypeNumber { Odd = 1, Even = 2 };

enCheckTypeNumber checkNumberType(short number) {
    short result = number % 2;
    if (result != 0) {
        return enCheckTypeNumber::Odd;
    }
    else {
        return enCheckTypeNumber::Even;
    }

}

void printNumber(enCheckTypeNumber numberType) {

    if (numberType == enCheckTypeNumber::Even) {
        cout << "Your number is Even";
    }
    else {
        cout << "Your number is Odd";
    }

}


int main()
{

    printNumber(checkNumberType(readNumberFromUser()));

    return 0;

}/*
 output
 Please enter a number
10
Your number is Even
 */