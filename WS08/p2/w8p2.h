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


// ----------------------------------------------------------------------------
// macro's
# define MAX_PRODUCTS 3
# define GRAMS_PER_SERVING 64
# define LBS_TO_KG_FACTOR 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    int calPerServing;
    double weightLbs;
};

struct ReportData
{
    int sku;
    double price;
    int calPerServing;
    double weightLbs;
    double weightKg;
    int weightG;
    double totalServings;
    double costPerServing;
    double costPerCal;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* ptrIntNum);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* ptrDblNum);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqProduct);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* ptrPrice, const double* ptrWeightLbs,
    const int calPerServing);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* ptrWeightLbs, double* ptrWeightKg);

// 9. convert lbs: g
int convertLbsG(const double* ptrWeightLbs, int* ptrWeightG);

// 10. convert lbs: kg / g
void convertLbs(const double* ptrWeightLbs, double* ptrWeightKg, int* ptrWeightG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int gramsPerServing, const int totalGrams,
                         double* ptrTotalServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* ptrPrice, const double* ptrTotalServings,
                               double* ptrCostPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* ptrCostPerServing, const double* ptrCalPerServing,
                           double* ptrCostPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo product);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData product, const int isCheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
