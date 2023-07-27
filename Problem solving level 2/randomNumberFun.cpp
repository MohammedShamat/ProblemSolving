#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

int randomNumberFun(short from, short to) {
	int number = rand() % (to - from + 1) + from;
	return number;

}


int main() {
	srand((unsigned)time(NULL));
	cout << "Random Number between 1 and 10: " << randomNumberFun(1, 10) << endl;
	cout << "Random Number between 1 and 5: " << randomNumberFun(1, 5)<<endl;
	cout << "Random Number between 100 and 200: " << randomNumberFun(100, 200);
}

/*
output

Random Number between 1 and 10: 10
Random Number between 1 and 5: 1
Random Number between 100 and 200: 166
*/