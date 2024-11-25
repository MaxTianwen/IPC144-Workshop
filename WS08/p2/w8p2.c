/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* ptrWeightLbs, double* ptrWeightKg)
{
	double weightKg;

	weightKg = *ptrWeightLbs / LBS_TO_KG_FACTOR;

	if (ptrWeightKg != NULL)
	{
		*ptrWeightKg = weightKg;
	}

	return weightKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* ptrWeightLbs, int* ptrWeightG)
{
	int weightG;

	weightG = (*ptrWeightLbs / LBS_TO_KG_FACTOR) * 1000;

	if (ptrWeightG != NULL)
	{
		*ptrWeightG = weightG;
	}

	return weightG;
}


// 10. convert lbs: kg and g
void convertLbs(const double* ptrWeightLbs, double* ptrWeightKg, int* ptrWeightG)
{
	convertLbsKg(ptrWeightLbs, ptrWeightKg);
	convertLbsG(ptrWeightLbs, ptrWeightG);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gramsPerServing, const int totalGrams,
						 double* ptrTotalServings)
{
	double totalServings;

	totalServings = ((double)totalGrams) / gramsPerServing;

	if (ptrTotalServings != NULL)
	{
		*ptrTotalServings = totalServings;
	}

	return totalServings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* ptrPrice, const double* ptrTotalServings,
							   double* ptrCostPerServing)
{
	double costPerServing;

	costPerServing = *ptrPrice / *ptrTotalServings;

	if (ptrCostPerServing != NULL)
	{
		*ptrCostPerServing = costPerServing;
	}

	return costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* ptrPrice, const double* ptrTotalCal,
						   double* ptrCostPerCal)
{
	double costPerCal;

	costPerCal = *ptrPrice / *ptrTotalCal;

	if (ptrCostPerCal != NULL)
	{
		*ptrCostPerCal = costPerCal;
	}

	return costPerCal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo foodProduct)
{
	struct ReportData productData = { 0 };
	double totalCalories;

	productData.sku = foodProduct.sku;
	productData.price = foodProduct.price;
	productData.calPerServing = foodProduct.calPerServing;
	productData.weightLbs = foodProduct.weightLbs;

	convertLbs(&productData.weightLbs, &productData.weightKg, &productData.weightG);
	calculateServings(GRAMS_PER_SERVING, productData.weightG, &productData.totalServings);
	calculateCostPerServing(&productData.price, &productData.totalServings,
							&productData.costPerServing);

	// calculate total calories
	totalCalories = productData.calPerServing * productData.totalServings;
	calculateCostPerCal(&productData.price, &totalCalories, &productData.costPerCal);

	return productData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_PER_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData product, const int isCheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", product.sku,
			product.price, product.weightLbs, product.weightKg, product.weightG,
			product.calPerServing, product.totalServings, product.costPerServing,
			product.costPerCal);

	// determine whether this product is the cheapest one
	if (isCheapest)
	{
		printf(" ***");
	}
	putchar('\n');
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct)
{
	putchar('\n');
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", cheapestProduct.sku, cheapestProduct.price);

	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo foodInfo[MAX_PRODUCTS] = { { 0 } };
	struct ReportData productData[MAX_PRODUCTS] = { { 0 } };

	double cheapestCost;
	int cheapestProductIndex;

	int i;

	// display opening message
	openingMessage(MAX_PRODUCTS);

	// get input for food products
	for (i = 0; i < MAX_PRODUCTS; ++i)
	{
		foodInfo[i] = getCatFoodInfo(i);
		productData[i] = calculateReportData(foodInfo[i]);
	}

	// determine the cheapest product
	cheapestCost = productData[0].costPerServing;
	cheapestProductIndex = 0;
	for (i = 1; i < MAX_PRODUCTS; ++i)
	{
		if (productData[i].costPerServing < cheapestCost)
		{
			cheapestCost = productData[i].costPerServing;
			cheapestProductIndex = i;
		}
	}

	// display CatFoodInfo
	// header
	displayCatFoodHeader();

	// content
	for (i = 0; i < MAX_PRODUCTS; ++i)
	{
		displayCatFoodData(foodInfo[i].sku, &foodInfo[i].price, &foodInfo[i].weightLbs,
						   foodInfo[i].calPerServing);
	}

	// display ReportData 
	// header
	putchar('\n');
	displayReportHeader();

	// content
	for (i = 0; i < MAX_PRODUCTS; ++i)
	{
		if (i == cheapestProductIndex)
		{
			displayReportData(productData[i], 1);
		}
		else
		{
			displayReportData(productData[i], 0);
		}
	}

	// final analysis
	displayFinalAnalysis(foodInfo[cheapestProductIndex]);
}
