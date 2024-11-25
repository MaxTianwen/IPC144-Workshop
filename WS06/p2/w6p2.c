/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
#define YES 'y' 
#define NO 'n'

#define MENU_QUIT 0
#define MENU_ALL_ITEMS 1
#define MENU_BY_PRIORITY 2


int main(void)
{
	// Value Ranges
	const double MIN_MONTHLY_INCOME = 500.00, MAX_MONTHLY_INCOME = 400000.00;
	const double MIN_COST = 100.00;

	// Input variables
	double mothlyIncome, totalCost;
	int itemsNum;
	int menuSel, prioritySel;

	// Parallel arrays for item information
	double cost[MAX_ITEMS_NUM] = { 0 };
	int priority[MAX_ITEMS_NUM] = { 0 };
	char financeOpt[MAX_ITEMS_NUM] = { 0 };

	int i;	// Iterator
	int valid, note;	// Flags


	// Title
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	// Input monthly income
	do {
		valid = 1;	// Initialize the loop flag

		printf("Enter your monthly NET income: $");
		scanf("%lf", &mothlyIncome);

		// Check if the monthly income is valid
		if (mothlyIncome < MIN_MONTHLY_INCOME)
		{
			printf("ERROR: You must have a consistent monthly income of at least "
				   "$%.2lf\n", MIN_MONTHLY_INCOME);
			valid = 0;
		}
		else if (mothlyIncome > MAX_MONTHLY_INCOME)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than "
				   "$%.2lf\n", MAX_MONTHLY_INCOME);
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

			printf("   Does this item have financing options? [%c/%c]: ", YES,
				   NO);
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
		totalCost += cost[i];	// Calculate the total cost for summary
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOpt[i],
			cost[i]);
	}

	// Total cost
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);


	// Input menu selection until the value is valid
	do {
		// Print the menu
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &menuSel);
		putchar('\n');

		// Check user's selection
		// Input value out of range
		if (menuSel != MENU_QUIT && menuSel != MENU_ALL_ITEMS &&
			menuSel != MENU_BY_PRIORITY)
		{
			printf("ERROR: Invalid menu selection.\n\n");
		}
		// 1: display all wish list items
		else if (menuSel == MENU_ALL_ITEMS)
		{
			// Calculate total cost and record finance options
			totalCost = 0, note = 0;
			for (i = 0; i < itemsNum; ++i)
			{
				totalCost += cost[i];	// Cost for all items
				if (financeOpt[i] == 'y')
				{
					note = 1;	// Note for finance options
				}
			}

			// Output
			printf("====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", totalCost);
			printf("Forecast: %d years, %d months\n", 
				   ((int)(totalCost / mothlyIncome + 0.99)) / 12,
				   ((int)(totalCost / mothlyIncome + 0.99)) % 12);
			if (note)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n\n");
		}
		// 2: display the specified priority items
		else if (menuSel == MENU_BY_PRIORITY)
		{
			totalCost = 0, note = 0;
			// Prompt input for priority filtering
			printf("What priority do you want to filter by? [1-3]: ");
			scanf("%d", &prioritySel);

			for (i = 0; i < itemsNum; ++i)
			{
				if (priority[i] == prioritySel)
				{
					totalCost += cost[i];	// Calculate totalCost for the choosen priority
					if (financeOpt[i] == 'y')
					{
						note = 1;	// Note for finance options
					}
				}
			}

			// Print the filtered priority
			putchar('\n');
			printf("====================================================\n");
			printf("Filter:   by priority (%d)\n", prioritySel);
			printf("Amount:   $%1.2lf\n", totalCost);
			printf("Forecast: %d years, %d months\n", 
				   ((int)(totalCost / mothlyIncome + 0.99)) / 12,
				   ((int)(totalCost / mothlyIncome + 0.99)) % 12);
			if (note)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n\n");

		}
	} while (menuSel);

	// 0: Quit
	printf("Best of luck in all your future endeavours!\n");


    return 0;
}