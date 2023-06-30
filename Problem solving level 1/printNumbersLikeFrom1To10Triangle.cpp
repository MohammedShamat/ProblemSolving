#include <iostream>
using namespace std;




int main()
{
	for (short numberRow = 1; numberRow <= 10; numberRow++) {

		for (short numberColumn = numberRow; numberColumn <= 10; numberColumn++) {
			cout << numberColumn;
		}
		cout << "\n";
	}

	/*output

    12345678910
    2345678910
    345678910
    45678910
    5678910
    678910
    78910
    8910
    910
    10

	*/

}