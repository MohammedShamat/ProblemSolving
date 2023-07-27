#include <iostream>
#include <string>
using namespace std;

string readFromUser(string message) {
	string text = "";
	cout << message << endl;
	getline(cin, text);
	return text;
}
string encryptionText(string textFromUser, short encryptionkey) {

	for (short indexOfString = 0; indexOfString <= textFromUser.length(); indexOfString++) {

		textFromUser[indexOfString] = char((int)textFromUser[indexOfString] + encryptionkey);

	}
	return textFromUser;
}
string decryptionText(string text, short encryptionkey) {

	for (short indexOfString = 0; indexOfString <= text.length(); indexOfString++) {

		text[indexOfString] = char((int)text[indexOfString] - encryptionkey);

	}
	return text;

}



int main() {
	const short encryptionkey = 2;
	string text = readFromUser("Please Enter a Text");
	string afterEncryption = encryptionText(text, encryptionkey);
	string afterDecryption = decryptionText(afterEncryption, encryptionkey);
	cout << "After Encryption: " << afterEncryption;
	cout << "\nBefore Encryption: " << afterDecryption;
}/*


Please Enter a Text
Programming Advices

output is :

After Encryption: Rtqitcookpi"Cfxkegu
Before Encryption: Programming Advices
 */