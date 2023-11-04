#include<iostream>
#include<string>
#include<vector>
using  namespace std;
struct ClientData {
	string accNumber = "";
	string pinCode = "";
	string nameClient = "";
	string phoneNumber = "";
	double accBalance = 0.0;
};
string PrintMenu(string message) {
	cout << message << endl;
	return message;
}
ClientData GetDataFromClient() {
	PrintMenu("Please Enter Client Data :");
	ClientData dataFromClient;
	cout << "\nEnter Account Number ? "; getline(cin, dataFromClient.accNumber);
	cout << "Enter PinCode ? "; getline(cin, dataFromClient.pinCode);
	cout << "Enter Full Name ? "; getline(cin, dataFromClient.nameClient);
	cout << "Enter Phone ? ";  getline(cin, dataFromClient.phoneNumber);
	cout << "Enter Account Balance ? "; cin >> dataFromClient.accBalance;

	return dataFromClient;
}
string ConvertClientDataToline(ClientData dataFromClient, string delimiter) {
	string clientDataInLine = "";
	cout << "\n\nClient Record For Saving is :\n";
	clientDataInLine += dataFromClient.accNumber + delimiter;
	clientDataInLine += dataFromClient.pinCode + delimiter;
	clientDataInLine += dataFromClient.nameClient + delimiter;
	clientDataInLine += dataFromClient.phoneNumber + delimiter;
	clientDataInLine += to_string(dataFromClient.accBalance);
	return clientDataInLine;
}
int main() {

	cout << ConvertClientDataToline(GetDataFromClient(), "#//#");

}

/*
output :

Please Enter Client Data :

Enter Account Number ? A1586
Enter PinCode ? 47856
Enter Full Name ? Moahmmed shamat
Enter Phone ? 05693686
Enter Account Balance ? 548630


Client Record For Saving is :
A1586#//#47856#//#Moahmmed shamat#//#05693686#//#548630.000000

*/