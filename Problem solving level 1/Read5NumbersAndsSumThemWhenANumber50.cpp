#include <iostream>
using namespace std;

double sumNumbersBelow50(double arrayNumbers[5]) {
    
    double sum=0.0 ;
    for (short index = 0; index <= 4; index++) {
        if (arrayNumbers[index] > 50) {
            continue;
        }
        sum += arrayNumbers[index];

    }

    return sum;
}

int main()
    {
    double arrayNumbers[5] = {5,50,35,55,53};
    
   
    cout << sumNumbersBelow50(arrayNumbers) << endl;
    
	}
/* Read 5 numbers and sum them up as long as the number is below 50 use for loop and continue statement 
intput:
10,20,55,10,20

output = 60

*/