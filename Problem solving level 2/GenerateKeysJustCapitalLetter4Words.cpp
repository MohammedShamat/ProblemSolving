#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

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



	int randomNumberFun(short from, short to) {

		int number = rand() % (to - from + 1) + from;
		return number;

	}

	void keysToGenerate(int times) {
		string underScor = "-";
		for (int counter = 1; counter <= times; counter++) {
			cout << "Key[" << counter << "] : ";
			for (int counterSecond = 1; counterSecond <= 19; counterSecond++) {
				if (counterSecond == 5 || counterSecond == 10 || counterSecond == 15) {
					cout << underScor;
				}
				else {
					cout << char(randomNumberFun(65, 90));
				}

			}


			cout << endl;
		}


	}



	int main() {

		srand((unsigned)time(NULL));
		keysToGenerate(readNumberFromUser("Please Enter how Times Want"));
	}


	/*
	Please Enter how Times Want
-99
Invalid Number, Enter a valid one
tr
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
5
Key[1] : CTIM-QEHE-JMLS-OBUD
Key[2] : ATZA-BIKU-NWKJ-MEQD
Key[3] : NKWY-RQPF-ZYGI-ZINN
Key[4] : UKTY-LTHJ-JVOA-HAJU
Key[5] : OUDU-FUZT-TFLH-MVOS

	*/