#include <iostream>
#include <string>
using namespace std;

enum passOrFail {
    pass = 1,
    fail = 2
};

float readMark() {
    float mark;
    cout << "Please Enter Your mark\n";
    cin >> mark;
    while (cin.fail()||mark<0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please Enter a valid value\n";
        cin >> mark;
    }
    return mark;
}

passOrFail checkMark(float mark) {
    if (mark >= 50) {
        return passOrFail::pass;
    }
    else {
        return passOrFail::fail;
    }


}

void printResult(passOrFail check) {
    if (check == passOrFail::pass) {
        cout << "Passed" << endl;
    }
    else {
        cout << "Failed" << endl;
    }

}


int main()
{
    printResult(checkMark(readMark()));

    return 0;

}/*
 Please Enter Your mark
sss
Please Enter a valid value
-12
Please Enter a valid value
50
Passed
*/