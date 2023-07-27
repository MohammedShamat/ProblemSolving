#include <iostream>
#include <string>
using namespace std;



void printLetterPatternFromAAAToZZZ() {

	cout << "Letter Pattern From AAA To ZZZ \n\n";

	for (short firstLetter = 65; firstLetter <= 90; firstLetter++) {
		for (short secondeLetter = 65; secondeLetter <= 90; secondeLetter++) {
			for (short thirdLetter = 65; thirdLetter <= 90; thirdLetter++) {
				cout << char(firstLetter) << char(secondeLetter) << char(thirdLetter);
				cout << endl;
			}


		}



	}

}


int main() {

	printLetterPatternFromAAAToZZZ();
	return 0;
}/*


Letter Pattern FromAAA To ZZZ

AAA
AAB
AAC
AAD
...
...
ZZZ
 */