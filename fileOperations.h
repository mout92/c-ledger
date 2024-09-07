#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

extern int transactions_array_size;

void loadTransactions(Transaction *transactions[]);
void saveTransactions(Transaction *transactions[]);

#endif
