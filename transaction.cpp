//
// Created by Arias Arevalo, Carlos on 10/26/20.
//

#include "transaction.h"

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;
using std::endl;

bool ReadTransaction(istream& input, Transaction& transaction){
	if (input.fail())
		return false;
	input >> transaction.day >> transaction.month >> transaction.year
		  >> transaction.merchant >> transaction.amount;
	return !input.fail();
}
bool WriteTransaction(ostream& output, const Transaction& transaction){
	output << transaction.day << " " << transaction.month << " " << transaction.year
		   << " " << transaction.merchant << " " << transaction.amount;
	return !output.fail();
}
void InitTransactions(Transactions& transactions){
	transactions.count = 0;
}
bool AddTransaction(Transactions& transactions, const Transaction& transaction){
	if (transactions.count == MAX_TRANSACTIONS)
		return false;
	transactions.transactions[transactions.count] = transaction;
	transactions.count++;
	return true;
}
int WriteTransactions(ostream& output, const Transactions& transactions){
	if (output.fail()){
		return -1;
	}
	unsigned int transactionsWritten = 0;
	for (unsigned int i = 0; i < transactions.count; ++i) {
		WriteTransaction(output, transactions.transactions[i]);
		output << endl;
		transactionsWritten++;
	}
	return transactionsWritten;
}
int ReadTransactions(istream& input, Transactions& transactions){
	if (input.fail())
		return -1;
	Transaction aTransaction;
	unsigned int transactionsRead = 0;
	while(ReadTransaction(input, aTransaction)) {
		if (AddTransaction(transactions, aTransaction))
			transactionsRead++;
		else
			break;
	}
	return transactionsRead;
}
double TotalTransactions(const Transactions& transactions){
	double total = 0.0;
	for (unsigned int i = 0; i < transactions.count; ++i) {
		total += transactions.transactions[i].amount;
	}
	return total;
}
double TotalTransactionsPerYear(const Transactions& transactions, unsigned int year){
	return -1;
}
