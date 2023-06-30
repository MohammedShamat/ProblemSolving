#include <iostream>
using namespace std;

int main()
{
	for (short starRow = 1; starRow <= 10; starRow++ ) {
		for (short starColumn = 10; starColumn >= starRow; starColumn--) {
			cout << "*";
		}
		cout << "\n";
	}

	/*output

	  **********
          *********
          ********
          *******
          ******
          *****
          ****
          ***
          **
          *

	*/

}