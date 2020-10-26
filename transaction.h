//
// Created by Arias Arevalo, Carlos on 10/26/20.
//

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;

const int MAX_TRANSACTIONS = 5;

struct Transaction{
	unsigned short int day;
	unsigned short int month;
	unsigned short int year;
	double amount;
	string merchant;
};

struct Transactions{
	unsigned int count;
	Transaction transactions[MAX_TRANSACTIONS];
};



bool ReadTransaction(istream& input, Transaction& transaction);
bool WriteTransaction(ostream& output, const Transaction& transaction);
void InitTransactions(Transactions& transactions);
bool AddTransaction(Transactions& transactions, const Transaction& transaction);
int WriteTransactions(ostream& output, const Transactions& transactions);
int ReadTransactions(istream& input, Transactions& transactions);
double TotalTransactions(const Transactions& transactions);
// Implement this function, it will sum all the amounts of the transactions of the given year
double TotalTransactionsPerYear(const Transactions& transactions, unsigned int year);


#endif //TRANSACTION_LIST_MULTIFILE_POINT_H
