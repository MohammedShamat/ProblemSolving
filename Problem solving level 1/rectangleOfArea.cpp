#include <iostream>
#include <string>
using namespace std;


void readNumbersFromUsers(float& number1, float& number2) {

    cout << "Please Enter First number ...\n";
    cin >> number1;
    while (cin.fail()|| number1 <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> number1;
    }
    cout << "Please Enter Second number ...\n";
    cin >> number2;
    while (cin.fail() || number2<=0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> number2;
    }

}
float areaOfRectangle(float firstNum, float SecondNum) {
    return firstNum * SecondNum;
}
void printArea(float area) {
    cout << "Rectangle area is " << area << endl;
}


int main()
{
    float firstnum, secondNum;
    readNumbersFromUsers(firstnum, secondNum);
    printArea(areaOfRectangle(firstnum, secondNum));

    return 0;

}/*Please Enter First number ...
0
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
nnk
Invalid Number, Enter a valid one
12
Please Enter Second number ...
15
Rectangle area is 180*/