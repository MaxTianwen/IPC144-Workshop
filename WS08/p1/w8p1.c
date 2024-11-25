/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* ptrIntNum)
{
	int intNum;
	int valid;

	// check input validity
	do {
		valid = 1;

		scanf("%d", &intNum);
		if (intNum <= 0)
		{
			valid = 0;
			printf("ERROR: Enter a positive value: ");
		}
	} while (!valid);

	// assign the input value to the value that the pointer points to
	if (ptrIntNum != NULL)
	{
		*ptrIntNum = intNum;
	}

	return intNum;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* ptrDblNum)
{
	double dblNum;
	int valid;

	// check input validity
	do {
		valid = 1;

		scanf("%lf", &dblNum);
		if (dblNum <= 0)
		{
			valid = 0;
			printf("ERROR: Enter a positive value: ");
		}
	} while (!valid);

	// assign the input value to the value that the pointer points to
	if (ptrDblNum != NULL)
	{
		*ptrDblNum = dblNum;
	}

	return dblNum;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n",
			numProducts);
	printf("NOTE: A 'serving' is %dg\n\n", GRAMS_PER_SERVING);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqProduct)
{
	struct CatFoodInfo product = { 0 };

	printf("Cat Food Product #%d\n", seqProduct + 1);
	printf("--------------------\n");

	// getting the return value via arguments
	printf("SKU           : ");
	getIntPositive(&product.sku);	
	
	printf("PRICE         : $");
	getDoublePositive(&product.price);	
	
	// getting the return value via "return" statement
	printf("WEIGHT (LBS)  : ");
	product.weightLbs = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	product.calPerServing = getIntPositive(NULL);

	putchar('\n');

	return product;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* ptrPrice, const double* ptrWeightLbs,
						const int calPerServing)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *ptrPrice, *ptrWeightLbs, calPerServing);
}

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo productInfo[MAX_PRODUCTS] = { { 0 } };

	int i;

	// display opening message
	openingMessage(MAX_PRODUCTS);

	// get input for food products
	for (i = 0; i < MAX_PRODUCTS; ++i)
	{
		productInfo[i] = getCatFoodInfo(i);
	}

	// display the table header
	displayCatFoodHeader();

	// display food information
	for (i = 0; i < MAX_PRODUCTS; ++i)
	{
		displayCatFoodData(productInfo[i].sku, &productInfo[i].price,
						   &productInfo[i].weightLbs, productInfo[i].calPerServing);
	}
}
