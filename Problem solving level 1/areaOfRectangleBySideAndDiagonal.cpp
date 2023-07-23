#include <iostream>

#include <cmath>

using namespace std;


void readNumbersFromUsers(float& number1, float& number2) {

    cout << "Please Enter First number ...\n";
    cin >> number1;
    while (cin.fail() || number1 <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> number1;
    }
    cout << "Please Enter Second number ...\n";
    cin >> number2;
    while (cin.fail() || number2 <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> number2;
    }

}
float areaOfRectangleBySideAndDiagonal(float firstNum, float SecondNum) {

    float area = firstNum * sqrt((SecondNum * SecondNum) - (firstNum * firstNum));
    return area;
}
void printArea(float area) {
    cout << "The area is " << area << endl;
}


int main()
{
    float firstnum, secondNum;
    readNumbersFromUsers(firstnum, secondNum);
    printArea(areaOfRectangleBySideAndDiagonal(firstnum, secondNum));




    return 0;

}/*
 Please Enter First number ...
-9
Invalid Number, Enter a valid one
aa
Invalid Number, Enter a valid one
15
Please Enter Second number ...
29
The area is 372.29*/