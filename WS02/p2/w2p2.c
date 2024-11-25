/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
	const int TOONIE = 200,
		      LOONIE = 100,
		      QUARTER = 25,
		      DIME = 10,
		      NICKEL = 5,
			  PENNIE = 1;

	double priceS, priceM, priceL;		// Prices of three different sizes

	int patCount, patPrice, patSub, patTaxes, patTotal;	
	int salCount, salPrice, salSub, salTaxes, salTotal;
	int tomCount, tomPrice, tomSub, tomTaxes, tomTotal;
	int	subtotal, taxes, total;

	int tooniesQty, looniesQty, quartersQty, dimesQty, nickelsQty, penniesQty;
	int balance;
	double avgCostExcTax, avgCostIncTax;	// Average cost per shirt excluding and including tax

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
	scanf("%d", &patCount);
	printf("\n");	
	
	printf("Tommy's shirt size is '%c'\n", tomSize);
	printf("Number of shirts Tommy is buying: ");
	scanf("%d", &tomCount);
	printf("\n");	
	
	printf("Sally's shirt size is '%c'\n", salSize);
	printf("Number of shirts Sally is buying: ");
	scanf("%d", &salCount);
	printf("\n");


	// Calculate the sales data
	// Patty
	patPrice = (priceS * 100) + 0.5;
	patSub = patPrice * patCount;
	patTaxes = (patSub * TAX) + 0.5;
	patTotal = patSub + patTaxes;

	// Sally
	salPrice = (priceM * 100) + 0.5;
	salSub = salPrice * salCount;
	salTaxes = (salSub * TAX) + 0.5;
	salTotal = salSub + salTaxes;

	// Tommy
	tomPrice = (priceL * 100) + 0.5;
	tomSub = tomPrice * tomCount;
	tomTaxes = (tomSub * TAX) + 0.5;
	tomTotal = tomSub + tomTaxes;

	// Total
	subtotal = patSub + salSub + tomSub;
	taxes = patTaxes + salTaxes + tomTaxes;
	total = subtotal + taxes;

	// Output the sales data as a table
	printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");

	printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, patPrice / 100.0,
			patCount, patSub / 100.0, patTaxes / 100.0, patTotal / 100.0);
	printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, salPrice / 100.0,
			salCount, salSub / 100.0, salTaxes / 100.0, salTotal / 100.0);	
	printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, tomPrice / 100.0,
			tomCount, tomSub / 100.0, tomTaxes / 100.0, tomTotal / 100.0);

	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("%33.4lf %9.4lf %9.4lf\n\n", subtotal / 100.0, taxes / 100.0, total / 100.0);




	// Output sales data represented by coins
	printf("Daily retail sales represented by coins\n");
	printf("=======================================\n\n");

	// Column names of sales excluding tax
	printf("Sales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");

	// Total balance
	balance = subtotal;
	printf("%22.4lf\n", balance / 100.0);

	// Toonies
	tooniesQty = balance / TOONIE;
	balance %= TOONIE;
	printf("Toonies  %3d %9.4lf\n", tooniesQty, balance / 100.0);	
	
	// Loonies
	looniesQty = balance / LOONIE;
	balance %= LOONIE;
	printf("Loonies  %3d %9.4lf\n", looniesQty, balance / 100.0);

	// Quarters
	quartersQty = balance / QUARTER;
	balance %= QUARTER;
	printf("Quarters %3d %9.4lf\n", quartersQty, balance / 100.0);

	// Dimes
	dimesQty = balance / DIME;
	balance %= DIME;
	printf("Dimes    %3d %9.4lf\n", dimesQty, balance / 100.0);

	// Nickels
	nickelsQty = balance / NICKEL;
	balance %= NICKEL;
	printf("Nickels  %3d %9.4lf\n", nickelsQty, balance / 100.0);

	// Pennies
	penniesQty = balance / PENNIE;
	balance %= PENNIE;
	printf("Pennies  %3d %9.4lf\n\n", penniesQty, balance / 100.0);

	// Average
	avgCostExcTax = (subtotal / 100.0) / (patCount + salCount + tomCount);
	printf("Average cost/shirt: $%.4lf\n\n", avgCostExcTax);


	// Column names of sales ixcluding tax
	printf("Sales INCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");

	// Total balance
	balance = total;
	printf("%22.4lf\n", balance / 100.0);

	// Toonies
	tooniesQty = balance / TOONIE;
	balance %= TOONIE;
	printf("Toonies  %3d %9.4lf\n", tooniesQty, balance / 100.0);

	// Loonies
	looniesQty = balance / LOONIE;
	balance %= LOONIE;
	printf("Loonies  %3d %9.4lf\n", looniesQty, balance / 100.0);

	// Quarters
	quartersQty = balance / QUARTER;
	balance %= QUARTER;
	printf("Quarters %3d %9.4lf\n", quartersQty, balance / 100.0);

	// Dimes
	dimesQty = balance / DIME;
	balance %= DIME;
	printf("Dimes    %3d %9.4lf\n", dimesQty, balance / 100.0);

	// Nickels
	nickelsQty = balance / NICKEL;
	balance %= NICKEL;
	printf("Nickels  %3d %9.4lf\n", nickelsQty, balance / 100.0);

	// Pennies
	penniesQty = balance / PENNIE;
	balance %= PENNIE;
	printf("Pennies  %3d %9.4lf\n\n", penniesQty, balance / 100.0);

	// Average
	avgCostIncTax = (total / 100.0) / (patCount + salCount + tomCount);
	printf("Average cost/shirt: $%.4lf\n", avgCostIncTax);

    return 0;
}