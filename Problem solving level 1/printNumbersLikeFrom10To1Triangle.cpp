#include <iostream>
using namespace std;




int main()
{
	for (short numberRow = 10; numberRow >= 1; numberRow--) {

		for (short numberColumn = numberRow; numberColumn <= 10; numberColumn++) {
			cout << numberColumn;
		}
		cout << "\n";
	}

	/*output

	10
        910
        8910
        78910
        678910
        5678910
        45678910
        345678910
        2345678910
        12345678910

	*/

}