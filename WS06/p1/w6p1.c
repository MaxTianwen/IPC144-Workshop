/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Tianwen Wang
Student ID#: 151583226
Email      : twang118@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_ITEMS_NUM 1
#define MAX_ITEMS_NUM 10
#define MIN_PRIORITY 1
#define MAX_PRIORITY 3
#define OPT_YES 'y' 
#define OPT_NO 'n'

int main(void)
{
	// Value Ranges
	const double MIN_MO_INCOME = 500.00, MAX_MO_INCOME = 400000.00;
	const double MIN_COST = 100.00;

	// Input variables
	double moIncome;
	int itemsNum;
	double totalCost;

	// Parallel arrays for item properties
	double cost[MAX_ITEMS_NUM] = { 0 };
	int priority[MAX_ITEMS_NUM] = { 0 };
	char financeOpt[MAX_ITEMS_NUM] = { 0 };

	int i;	// Iterator
	int valid;	// Loop flag


	// Title
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	// Input monthly income
	do {
		valid = 1;	// Initialize the loop flag

		printf("Enter your monthly NET income: $");
		scanf("%lf", &moIncome);

		// Check if the monthly income is valid
		if (moIncome < MIN_MO_INCOME)
		{
			printf("ERROR: You must have a consistent monthly income of at least "
				   "$%.2lf\n", MIN_MO_INCOME);
			valid = 0;
		}
		else if (moIncome > MAX_MO_INCOME)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than "
				   "$%.2lf\n", MAX_MO_INCOME);
			valid = 0;
		}
		putchar('\n');
	} while (!valid);

	// Input number of wish list items
	do {
		valid = 1;	// Initialize the loop flag

		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &itemsNum);

		// Check if the number of items is valid
		if (itemsNum < MIN_ITEMS_NUM || itemsNum > MAX_ITEMS_NUM)
		{
			printf("ERROR: List is restricted to between %d and %d items.\n",
				   MIN_ITEMS_NUM, MAX_ITEMS_NUM);
			valid = 0;
		}
		putchar('\n');
	} while (!valid);

	// Input item details
	for (i = 0; i < itemsNum; ++i)
	{
		printf("Item-%d Details:\n", i + 1);
		// Cost
		do {
			valid = 1;

			printf("   Item cost: $");
			scanf("%lf", &cost[i]);

			// Check validity
			if (cost[i] < MIN_COST)
			{
				printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
				valid = 0;
			}
		} while (!valid);

		// Priority
		do {
			valid = 1;

			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);

			// Check validity
			if (priority[i] < MIN_PRIORITY || priority[i] > MAX_PRIORITY)
			{
				printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY
					   , MAX_PRIORITY);
				valid = 0;
			}
		} while (!valid);

		// Finance Option
		do {
			valid = 1;

			printf("   Does this item have financing options? [%c/%c]: ", OPT_YES,
				   OPT_NO);
			scanf(" %c", &financeOpt[i]);

			// Check validity
			if (!(financeOpt[i] == 'y' || financeOpt[i] == 'n'))
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
				valid = 0;
			}
		} while (!valid);

		putchar('\n');
	}

	// Output summary
	// Table header
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	// Results of the three parallel arrays
	totalCost = 0;
	for (i = 0; i < itemsNum; ++i)
	{
		totalCost += cost[i];	// Calculate the total cost
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOpt[i],
			   cost[i]);
	}

	// Total cost
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);

	// End
	printf("Best of luck in all your future endeavours!\n");


    return 0;
}

/*
    HELPER: printf formatting statements....
	=========================================
	
    Step #7:
		printf("Item Priority Financed        Cost\n");
		printf("---- -------- -------- -----------\n");
		
		printf("%3d  %5d    %5c    %11.2lf\n", ...
		

	Step #8:
		printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", ...

*/