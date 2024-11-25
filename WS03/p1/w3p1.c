/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Tianwen Wang
Student ID#: 151583226
Email      : twang118@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    const int IDP1 = 111, IDP2 = 222, IDP3 = 111;
    const double PRICEP1 = 111.49, PRICEP2 = 222.99, PRICEP3 = 334.49;
    const char TAXEDP1 = 'Y', TAXEDP2 = 'N', TAXEDP3 = 'N';

    double avgPrice;

    // Production information part
    printf("Product Information\n");
    printf("===================\n");

    // Product 1
    printf("Product-1 (ID:%d)\n", IDP1);
    printf("  Taxed: %c\n", TAXEDP1);
    printf("  Price: $%.4lf\n\n", PRICEP1);

    // Product 2
    printf("Product-2 (ID:%d)\n", IDP2);
    printf("  Taxed: %c\n", TAXEDP2);
    printf("  Price: $%.4lf\n\n", PRICEP2);    
    
    // Product 3
    printf("Product-3 (ID:%d)\n", IDP3);
    printf("  Taxed: %c\n", TAXEDP3);
    printf("  Price: $%.4lf\n\n", PRICEP3);

    // Average price
    avgPrice = (PRICEP1 + PRICEP2 + PRICEP3) / 3;
    printf("The average of all prices is: $%.4lf\n\n", avgPrice);


    // Relational and logical expressions part
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");


    // Data analysis part
    printf("Some Data Analysis...\n");
    printf("=====================\n");

    // Questions
    printf("1. Is product 1 taxable? -> %d\n\n", TAXEDP1 == 'Y');

    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", 
            TAXEDP2 == 'N' && TAXEDP3 == 'N');

    printf("3. Is product 3 less than testValue ($330.99)? -> %d\n\n", 
            PRICEP3 < testValue);

    printf("4. Is the price of product 3 more than both product 1 and 2 combined? "
           "-> %d\n\n", PRICEP3 > (PRICEP1 + PRICEP2));

    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", 
            PRICEP1 >= (PRICEP3 - PRICEP2), (PRICEP3 - PRICEP2));

    printf("6. Is the price of product 2 equal to or more than the average price? "
           "-> %d\n\n", PRICEP2 >= avgPrice);

    printf("7. Based on product ID, product 1 is unique -> %d\n\n", 
            IDP1 != IDP2 && IDP1 != IDP3);

    printf("8. Based on product ID, product 2 is unique -> %d\n\n", 
            IDP2 != IDP1 && IDP2 != IDP3);

    printf("9. Based on product ID, product 3 is unique -> %d\n", 
            IDP3 != IDP1 && IDP3 != IDP2);


    return 0;
}