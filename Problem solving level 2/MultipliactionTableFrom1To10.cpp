#include <iostream>
#include <string>
using namespace std;
void printHeaderOfTable() {
	string line = "\n______________________________________________________________________________________\n";
	string nameOfTable = "\n\n\t\t\tMultipliaction Table From 1 To 10\n\n\t";
	cout << nameOfTable;
	for (short forHeader = 1; forHeader <= 10; forHeader++) {
		cout << forHeader << "\t";
	}
	cout << line;

}
string solveSpace(short space) {
	if (space<10) {
		return"    |\t";
	}
	else {
		return "   |\t";
	}
}
void printMultipliactionTable(){
	printHeaderOfTable();
	for (short forColumn = 1; forColumn <= 10; forColumn++) {
		cout << " " << forColumn << solveSpace(forColumn);
		for (short rowOftable = 1; rowOftable <= 10; rowOftable++) {
			cout << forColumn * rowOftable << "\t";
		}
		cout << endl;
	}

}
int main() {
	printMultipliactionTable();
}
/*
output.....

			Multipliaction Table From 1 To 10

	1       2       3       4       5       6       7       8       9       10
______________________________________________________________________________________
 1    | 1       2       3       4       5       6       7       8       9       10
 2    | 2       4       6       8       10      12      14      16      18      20
 3    | 3       6       9       12      15      18      21      24      27      30
 4    | 4       8       12      16      20      24      28      32      36      40
 5    | 5       10      15      20      25      30      35      40      45      50
 6    | 6       12      18      24      30      36      42      48      54      60
 7    | 7       14      21      28      35      42      49      56      63      70
 8    | 8       16      24      32      40      48      56      64      72      80
 9    | 9       18      27      36      45      54      63      72      81      90
 10   | 10      20      30      40      50      60      70      80      90      100


*/