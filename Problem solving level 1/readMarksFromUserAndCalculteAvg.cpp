#include <iostream>
#include <string>
using namespace std;
enum passOrFail {

    pass = 1,
    fail = 2

};

void readMarksFromUsers(int& mark1, int& mark2, int& mark3) {
    cout << "Please Enter first mark to sum them...\n";
    cin >> mark1;
    while (cin.fail() || mark1 < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please Enter a valid value\n";
        cin >> mark1;
    }
    cout << "Please Enter Second mark to sum them...\n";
    cin >> mark2;
    while (cin.fail() || mark2 < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please Enter a valid value\n";
        cin >> mark2;
    }
    cout << "Please Enter Third mark to sum them...\n";
    cin >> mark3;
    while (cin.fail() || mark3 < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please Enter a valid value\n";
        cin >> mark3;
    }
}

int sumOfMarks(int num1, int num2, int num3) {
    int result = num1 + num2 + num3;
    return result;
}

float avgOfMarks(int mark1, int mark2, int mark3) {
    return(float)sumOfMarks(mark1, mark2, mark3) / 3;
}

passOrFail checkAvgOfMarks(float avgMarks) {
    if (avgMarks >= 60) {
        return passOrFail::pass;
    }
    else {
        return passOrFail::fail;
    }
}

void printResult(passOrFail avgMark) {
    if (avgMark == passOrFail::pass) {
        cout << "Passed" << endl;
    }
    else {
        cout << "Failed" << endl;
    }


}

int main()
{

    int mark1, mark2, mark3;
    readMarksFromUsers(mark1, mark2, mark3);
    printResult(checkAvgOfMarks(avgOfMarks(mark1, mark2, mark3)));
    cout << "\nYour AVG is " << avgOfMarks(mark1, mark2, mark3) << endl;




    return 0;

}/*
 Please Enter first mark to sum them...
qqq
Please Enter a valid value
-9
Please Enter a valid value
50
Please Enter Second mark to sum them...
60
Please Enter Third mark to sum them...
60
Failed

Your AVG is 56.6667
*/