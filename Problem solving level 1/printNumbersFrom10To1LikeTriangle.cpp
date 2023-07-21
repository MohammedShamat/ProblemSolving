#include <iostream>
using namespace std;




int main()
{
	for (short numberRow = 10; numberRow >= 1; numberRow-- ) {
		for (short numberColumn = 1; numberColumn <= numberRow; numberColumn++) {
			cout << numberColumn;
		}
		cout << "\n";
	}

	/*output
    12345678910
    123456789
    12345678
    1234567
    123456
    12345
    1234
    123
    12
    1

	*/

}