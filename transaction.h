#ifndef TRANSACTION_H
#define TRANSACTION_H

extern int transactions_array_size;

typedef struct {
	int id;
	int is_saved;		// bool for knowing if transaction is saved to disk.
	char store[256];
	int amount;
	int year;
	int month;
	int day;
} Transaction;

void printTransactions(Transaction *transactions[]);
void fancyPrintTransactions(Transaction *transactions[]);
void addTransaction(Transaction *transactions[]);

#endif
