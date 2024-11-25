/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #2 (P1)
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

int main(void)
{
	const double TAX = 0.13;
	const char patSize = 'S';

	double priceS, priceM, priceL;

	int patNum;	// Number of Patty shirts
	int priceInCents;
	int subtotal, taxes, total;


	// Set the prices
	printf("Set Shirt Prices\n");
	printf("================\n");

	printf("Enter the price for a SMALL shirt: $");
	scanf("%lf", &priceS);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%lf", &priceM);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%lf", &priceL);
	printf("\n");


	// List the prices
	printf("Shirt Store Price List\n");
	printf("======================\n");

	printf("SMALL  : $%.2lf\n", priceS);
	printf("MEDIUM : $%.2lf\n", priceM);
	printf("LARGE  : $%.2lf\n\n", priceL);


	// Get the size and numbers of buying
	printf("Patty's shirt size is '%c'\n", patSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &patNum);
	printf("\n");


	// Calculate the sales data in cents
	priceInCents = (priceS * 100) + 0.5;
	subtotal = priceInCents * patNum;
	taxes = (subtotal * TAX) + 0.5;
	total = subtotal + taxes;


	// Output
	printf("Patty's shopping cart...\n");
	printf("Contains : 8 shirts\n");
	printf("Sub-total: $%.4lf\n", subtotal / 100.0);
	printf("Taxes    : $ %.4lf\n", taxes / 100.0);
	printf("Total    : $%.4lf\n", total / 100.0);

	return 0;
}