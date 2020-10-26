#include <iostream>
#include <string>
#include <sstream>

#include "transaction.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ostream;
using std::istream;
using std::stringstream;


void ExampleOne();
void ExampleTwo();

int main() {
	stringstream data;
	data.str(
		"5 8 1999 gas 12.11 "
   		"9 10 1999 restaurant 55.12 "
   		"11 12 1999 groceries 121.00"
			);
	Transactions myTransactions;
	InitTransactions(myTransactions);
	ReadTransactions(data, myTransactions);
	WriteTransactions(cout, myTransactions);
	return 0;
}
void ExampleOne(){
	Transactions myTransactions;
	InitTransactions(myTransactions);
	cout << "Input Transactions:\n day month year merchant amout" << endl;
	cout << "Signal EOF when done" << endl;
	int totalRead = ReadTransactions(cin, myTransactions);
	if (totalRead == -1){
		cerr << "Something went wrong when reading";
		exit(1);
	}
	cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "Showing the transactions read: " << endl;
	WriteTransactions(cout, myTransactions);
	cout << "Total Amount Registered: " << TotalTransactions(myTransactions) << endl;

}

