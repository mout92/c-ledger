#include <stdio.h>
#include <stdlib.h>
#include "transaction.h"
#include "fileOperations.h"

int transactions_array_size = 0;

int main()
{
	Transaction *transactions = malloc(sizeof(Transaction) * 0);
	loadTransactions(&transactions);

	while(1)
	{
		system("clear");
		char menu_choice[128];
		printf("Welcome to the transaction application!\n\n");
		printf("1: Add a new transaction\n");
		printf("2: Print all transactions\n");
		printf("3: Save newly added transactions to file\n");
		printf("x: fancy print\n");
		printf("q: quit the application\n");
		printf("Please make a choice: ");
		fgets(menu_choice, 128, stdin);

		if (menu_choice[0] == 'q')
		{
			system("clear");
			break;
		}

		if (menu_choice[0] == '1')
		{
			system("clear");
			addTransaction(&transactions);
		}

		if (menu_choice[0] == '2')
		{
			system("clear");
			printTransactions(&transactions);
			printf("Press any key to continue ");
			getchar();
		}

		if (menu_choice[0] == '3')
		{
			system("clear");
			saveTransactions(&transactions);
			printf("Press any key to continue ");
			getchar();
		}

		if(menu_choice[0] == 'x')
		{
			system("clear");
			fancyPrintTransactions(&transactions);
			getchar();
		}
	}

	free(transactions);

	return 0;
}
