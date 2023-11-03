#include<iostream>
#include<string>
#include<cctype>
using  namespace std;
char ReadCharFrpmUser(string message) {
	char character = ' ';
	cout << message << endl;
	cin >> character;
	return character;
}
bool VowelLetter(char& letter) {
	letter = tolower(letter);
	return ('a' == letter || 'e' == letter || 'o' == letter || 'i' == letter || 'u' == letter);
}


void PrintResult(bool letter, char letterVowel) {
	letter ? cout << "Yes letter \' " << letterVowel << " \' is vowel " : cout << "NO letter \' " << letterVowel << " \' is not vowel ";

}
int main() {
	char fromUserChar = ReadCharFrpmUser("Please Enter a character?");
	PrintResult(VowelLetter(fromUserChar), fromUserChar);
}

/*
output :

Please Enter a character?
a
Yes letter ' a ' is vowel

or

Please Enter a character?
A
Yes letter ' a ' is vowel

or
Please Enter a character?
q
NO letter ' q ' is not vowel
*/