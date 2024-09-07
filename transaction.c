#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transaction.h"

void printTransactions(Transaction *transactions[])
{

	for(int i = 0; i < transactions_array_size; i++)
	{
		int dev_mode = 0;
		if (dev_mode == 1)
		{
			printf("id:     %i\n", (*transactions)[i].id);
			printf("saved:  %i\n", (*transactions)[i].is_saved);
		}

		printf("Store:  %s\n", (*transactions)[i].store);
		printf("Amount: €%i\n", (*transactions)[i].amount);

		// Month
		char month_string[32];
		if ((*transactions)[i].month < 10)
		{
			sprintf(month_string, "0%i", (*transactions)[i].month);
		}

		if ((*transactions)[i].month >= 10)
		{
			sprintf(month_string, "%i", (*transactions)[i].month);
		}

		char day_string[32];
		if ((*transactions)[i].day < 10)
		{
			sprintf(day_string, "0%i", (*transactions)[i].day);
		}

		if ((*transactions)[i].day>= 10)
		{
			sprintf(day_string, "%i", (*transactions)[i].day);
		}
		
		printf("Date:   %i-%s-%s\n",
				(*transactions)[i].year,
				month_string,
				day_string
		);

		printf("\n");
	}

	return;
}

void fancyPrintTransactions(Transaction *transaction[])
{
	printf("hello from facy print!");
	return;
}

void addTransaction(Transaction *transactions[])
{
	int t = transactions_array_size;
	transactions_array_size += 1;

	*transactions = realloc(*transactions,
			sizeof(Transaction) * transactions_array_size);

	(*transactions)[t].id = transactions_array_size;
	(*transactions)[t].is_saved = 0;

	// Getting store name
	printf("Enter store name: ");
	char string_buffer[256];
	fgets(string_buffer, 256, stdin);
	int string_buffer_length = strlen(string_buffer) - 1;
	string_buffer[string_buffer_length] = '\0';
	strcpy((*transactions)[t].store, string_buffer);

	printf("Enter amount: ");
	scanf("%i", &(*transactions)[t].amount);
	printf("Enter year: ");
	scanf("%i", &(*transactions)[t].year);

	// Month
	getchar();
	printf("Enter month: ");
	char month_string[128];
	fgets(month_string, 128, stdin);
	int month_int = atoi(month_string);
	(*transactions)[t].month = month_int;

	// Day
	printf("Enter day: ");
	char day_string[128];
	fgets(day_string, 128, stdin);
	int day_int = atoi(day_string);
	(*transactions)[t].day = day_int;

	return;
}
