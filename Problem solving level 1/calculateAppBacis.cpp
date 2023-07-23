#include <iostream>
using namespace std;

enum OpType {
	Add = '+',
	Sub = '-',
	Multiply = '*',
	Div = '/'
};


float readNumberFromUser(string message) {
	float number;
	cout << message << "\n";
	cin >> number;
	while (cin.fail() ) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}
OpType readOpType() {
	char opType = '+';
	cout << "Please Enter Operation Type + or - or * or / ?\n";
	cin >> opType;
	return (OpType)opType;
}
float calculate(float firstNumber, float secondeNumber, OpType opType)
{

	switch (opType)
	{
	case OpType::Add:
		return firstNumber + secondeNumber;

	case OpType::Sub:
		return  firstNumber - secondeNumber;

	case OpType::Multiply:
		return firstNumber * secondeNumber;


	case OpType::Div:
		return firstNumber / secondeNumber;


	default:
		return firstNumber + secondeNumber;

	}

}

int main()
{
	float firstNumber = readNumberFromUser("Please Enter First Number?\n");
	float secNumber = readNumberFromUser("Please Enter Second Number?\n");
	OpType operationType = readOpType();
	cout << calculate(firstNumber, secNumber, operationType) << endl;

}/*
 Please Enter First Number?

-50
Please Enter Second Number?

50
Please Enter Operation Type + or - or * or / ?
+
0
*/