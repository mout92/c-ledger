#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "transaction.h"
#include "fileOperations.h"

char file_path[] = "./data/transactions.csv";

void loadTransactions(Transaction *transactions[])
{
	FILE *fptr;

	fptr = fopen(file_path, "r");

	char input_buffer[256];

	while(fgets(input_buffer, 256, fptr))
	{
		int t = transactions_array_size;
		transactions_array_size += 1;

		*transactions = realloc(*transactions,
			sizeof(Transaction) * transactions_array_size);

		for(int i = 0; i < strlen(input_buffer); i++)
		{
			if(input_buffer[i] == '\n') input_buffer[i] = '\0';
		}

		char d[] = ",";

		char *id = strtok(input_buffer, d);
		int id_int = atoi(id);
		(*transactions)[t].id = id_int;
		// printf("id: %i\n", id_int);

		(*transactions)[t].is_saved = 1;
		// printf("is_saved: %i\n", (*transactions)[t].is_saved);

		char *store = strtok(NULL, d);
		strcpy((*transactions)[t].store, store);
		// printf("store: %s\n", store);

		char *amount = strtok(NULL, d);
		int amount_int = atoi(amount);
		(*transactions)[t].amount = amount_int;
		// printf("amount: %i\n", amount_int);

		char *year = strtok(NULL, d);
		int year_int = atoi(year);
		(*transactions)[t].year = year_int;
		// printf("year: %i\n", year_int);

		char *month = strtok(NULL, d);
		int month_int = atoi(month);
		(*transactions)[t].month = month_int;
		// printf("month: %i\n", month_int);

		char *day = strtok(NULL, d);
		int day_int = atoi(day);
		(*transactions)[t].day = day_int;
		// printf("day: %i\n", day_int);
		// printf("\n");
	}

	fclose(fptr);

	return;
}

void saveTransactions(Transaction *transactions[])
{
	int saved_counter = 0;
	FILE *fptr;
	fptr = fopen(file_path, "a");

	for(int i = 0; i < transactions_array_size; i++)
	{
		if ((*transactions)[i].is_saved == 0)
		{
			char row[1024];
			sprintf(row, "%i,%s,%i,%i,%i,%i",
				(*transactions)[i].id,
				(*transactions)[i].store,
				(*transactions)[i].amount,
				(*transactions)[i].year,
				(*transactions)[i].month,
				(*transactions)[i].day
				);

			fprintf(fptr, "%s\n", row);
			(*transactions)[i].is_saved = 1;
			saved_counter++;
		}
	}

	fclose(fptr);

	if (saved_counter == 0)
	{
		printf("No new transactions to save.");
	}

	if (saved_counter == 1)
	{
		printf("Saved %i transaction.\n", saved_counter);
	}
	
	if (saved_counter > 1)
	{
		printf("Saved %i transactions.\n", saved_counter);
	}

	printf("\n");

	return;
}
