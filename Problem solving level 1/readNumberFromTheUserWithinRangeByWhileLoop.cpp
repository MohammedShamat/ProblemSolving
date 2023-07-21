#include<iostream>
using namespace std;
//while loop
int readIntNumberInRange(int from, int to) {
	int number;
	cout << "pleas enter a number in this range " << from << " To " << to << endl;

	cin >> number;
	while (number < from || number > to) {
		cout << "wrong number\n";
		cout << "pleas enter a number in this range " << from << " To " << to << endl;
		cin >> number;
	}
	return number;
}




int main() {
	cout << "This is number true " << readIntNumberInRange(1, 18);
	return 0;
}/*
 output 
 pleas enter a number in this range 1 To 18
19
wrong number
pleas enter a number in this range 1 To 18
17
This is number true 17
 */