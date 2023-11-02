#include<iostream>
#include <vector>
using  namespace std;
void FibonacciSeries(vector <short>& fibonacciSer, short number) {
	for (short index = 0; index < number - 2; index++) {
		fibonacciSer.push_back(fibonacciSer.at(index) + fibonacciSer.at(index + 1));
	}
}
void PrintVector(vector <short>& fibonacciSer) {
	for (short& index : fibonacciSer) {
		cout << index << " ";
	}
}
int main() {
	vector <short> fibonacciSerOf10 = { 1,1 };
	FibonacciSeries(fibonacciSerOf10, 10);
	PrintVector(fibonacciSerOf10);

}
/*
output :
1 1 2 3 5 8 13 21 34 55
*/