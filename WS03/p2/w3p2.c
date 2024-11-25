/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    // Product information
    char typeCoffee1, typeCoffee2, typeCoffee3;
    int bagWtCoffee1, bagWtCoffee2, bagWtCoffee3;
    char creamCoffee1, creamCoffee2, creamCoffee3;

    // Personal preference
    char strengthPref, creamPref;
    int dailyServ;


    // Titles
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    // Coffee 1
    printf("COFFEE-1...\n");

    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c", &typeCoffee1);

    printf("Bag weight (g): ");
    scanf(" %d", &bagWtCoffee1);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamCoffee1);
    printf("\n");
    
    // Coffee 2
    printf("COFFEE-2...\n");

    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &typeCoffee2);

    printf("Bag weight (g): ");
    scanf(" %d", &bagWtCoffee2);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamCoffee2);
    printf("\n");

    // Coffee 3
    printf("COFFEE-3...\n");

    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &typeCoffee3);

    printf("Bag weight (g): ");
    scanf(" %d", &bagWtCoffee3);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamCoffee3);
    printf("\n");


    // Product table
    // Table header
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");

    // Coffee 1
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           typeCoffee1 == 'l' || typeCoffee1 == 'L', typeCoffee1 == 'm' || typeCoffee1 == 'M',
           typeCoffee1 == 'r' || typeCoffee1 == 'R', bagWtCoffee1, bagWtCoffee1 / GRAMS_IN_LBS,
           creamCoffee1 == 'y' || creamCoffee1 == 'Y');

    // Coffee 2
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           typeCoffee2 == 'l' || typeCoffee2 == 'L', typeCoffee2 == 'm' || typeCoffee2 == 'M',
           typeCoffee2 == 'r' || typeCoffee2 == 'R', bagWtCoffee2, bagWtCoffee2 / GRAMS_IN_LBS,
           creamCoffee2 == 'y' || creamCoffee2 == 'Y');

    // Coffee 3
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n",
           typeCoffee3 == 'l' || typeCoffee3 == 'L', typeCoffee3 == 'm' || typeCoffee3 == 'M',
           typeCoffee3 == 'r' || typeCoffee3 == 'R', bagWtCoffee3, bagWtCoffee3 / GRAMS_IN_LBS,
           creamCoffee3 == 'y' || creamCoffee3 == 'Y');


    // Personal Preference 1
    // Title
    printf("Enter how you like your coffee...\n\n");

    // Input from user
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strengthPref);

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamPref);

    printf("Typical number of daily servings: ");
    scanf("%d", &dailyServ);
    printf("\n");

    // Table 1
    printf("The below table shows how your preferences align to the available products:\n\n");

    // Table header
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    // Preference Coffee 1
    printf(" 1|       %d         |      %d      |   %d   |\n",
      ((strengthPref == 'l' || strengthPref == 'L') && (typeCoffee1 == 'l'|| typeCoffee1 == 'L')) ||
      ((strengthPref == 'm' || strengthPref == 'M')  && (typeCoffee1 == 'm' || typeCoffee1 == 'M'))||
      ((strengthPref == 'r' || strengthPref == 'R') && (typeCoffee1 == 'r' || typeCoffee1 == 'R'))

           , (dailyServ > 0 && dailyServ < 5 && bagWtCoffee1 == 250) || 
        (dailyServ > 4   && dailyServ < 10 && bagWtCoffee1 == 500) || 
        +(dailyServ > 9 && bagWtCoffee1 == 1000)

           , ((creamPref == 'y'|| creamPref == 'Y') && (creamCoffee1 == 'y'
           || creamCoffee1 == 'Y')) || ((creamPref == 'n' || creamPref == 'N')
           && (creamCoffee1 == 'n' || creamCoffee1 == 'N')));
    
    // Preference Coffee 2
    printf(" 2|       %d         |      %d      |   %d   |\n"
           , ((strengthPref == 'l' || strengthPref == 'L') && (typeCoffee2 == 'l'
           || typeCoffee2 == 'L')) || ((strengthPref == 'm' || strengthPref == 'M')
           && (typeCoffee2 == 'm' || typeCoffee2 == 'M')) || ((strengthPref == 'r'
           || strengthPref == 'R') && (typeCoffee2 == 'r' || typeCoffee2 == 'R'))
           , (dailyServ > 0 && dailyServ < 5 && bagWtCoffee2 == 250) || (dailyServ > 4
           && dailyServ < 10 && bagWtCoffee2 == 500) || (dailyServ > 9 && bagWtCoffee2 == 1000)
           , ((creamPref == 'y'|| creamPref == 'Y') && (creamCoffee2 == 'y'
           || creamCoffee2 == 'Y')) || ((creamPref == 'n' || creamPref == 'N')
           && (creamCoffee2 == 'n' || creamCoffee2 == 'N')));

    // Preference Coffee 3
    printf(" 3|       %d         |      %d      |   %d   |\n\n"
           , ((strengthPref == 'l' || strengthPref == 'L') && (typeCoffee3 == 'l'
           || typeCoffee3 == 'L')) || ((strengthPref == 'm' || strengthPref == 'M')
           && (typeCoffee3 == 'm' || typeCoffee3 == 'M')) || ((strengthPref == 'r'
           || strengthPref == 'R') && (typeCoffee3 == 'r' || typeCoffee3 == 'R'))
           , (dailyServ > 0 && dailyServ < 5 && bagWtCoffee3 == 250) || (dailyServ > 4
           && dailyServ < 10 && bagWtCoffee3 == 500) || (dailyServ > 9 && bagWtCoffee3 == 1000)
           , ((creamPref == 'y'|| creamPref == 'Y') && (creamCoffee3 == 'y'
           || creamCoffee3 == 'Y')) || ((creamPref == 'n' || creamPref == 'N')
           && (creamCoffee3 == 'n' || creamCoffee3 == 'N')));


    // Personal Preference 2
    // Title
    printf("Enter how you like your coffee...\n\n");

    // Input from user
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strengthPref);

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamPref);

    printf("Typical number of daily servings: ");
    scanf("%d", &dailyServ);
    printf("\n");

    // Table 2
    printf("The below table shows how your preferences align to the available products:\n\n");

    // Table header
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    // Preference Coffee 1
    printf(" 1|       %d         |      %d      |   %d   |\n"
           , ((strengthPref == 'l' || strengthPref == 'L') && (typeCoffee1 == 'l'
           || typeCoffee1 == 'L')) || ((strengthPref == 'm' || strengthPref == 'M')
           && (typeCoffee1 == 'm' || typeCoffee1 == 'M')) || ((strengthPref == 'r'
           || strengthPref == 'R') && (typeCoffee1 == 'r' || typeCoffee1 == 'R'))
           , (dailyServ > 0 && dailyServ < 5 && bagWtCoffee1 == 250) || (dailyServ > 4
           && dailyServ < 10 && bagWtCoffee1 == 500) || (dailyServ > 9 && bagWtCoffee1 == 1000)
           , ((creamPref == 'y'|| creamPref == 'Y') && (creamCoffee1 == 'y'
           || creamCoffee1 == 'Y')) || ((creamPref == 'n' || creamPref == 'N')
           && (creamCoffee1 == 'n' || creamCoffee1 == 'N')));
    
    // Preference Coffee 2
    printf(" 2|       %d         |      %d      |   %d   |\n"
           , ((strengthPref == 'l' || strengthPref == 'L') && (typeCoffee2 == 'l'
           || typeCoffee2 == 'L')) || ((strengthPref == 'm' || strengthPref == 'M')
           && (typeCoffee2 == 'm' || typeCoffee2 == 'M')) || ((strengthPref == 'r'
           || strengthPref == 'R') && (typeCoffee2 == 'r' || typeCoffee2 == 'R'))
           , (dailyServ > 0 && dailyServ < 5 && bagWtCoffee2 == 250) || (dailyServ > 4
           && dailyServ < 10 && bagWtCoffee2 == 500) || (dailyServ > 9 && bagWtCoffee2 == 1000)
           , ((creamPref == 'y'|| creamPref == 'Y') && (creamCoffee2 == 'y'
           || creamCoffee2 == 'Y')) || ((creamPref == 'n' || creamPref == 'N')
           && (creamCoffee2 == 'n' || creamCoffee2 == 'N')));

    // Preference Coffee 3
    printf(" 3|       %d         |      %d      |   %d   |\n\n"
           , ((strengthPref == 'l' || strengthPref == 'L') && (typeCoffee3 == 'l'
           || typeCoffee3 == 'L')) || ((strengthPref == 'm' || strengthPref == 'M')
           && (typeCoffee3 == 'm' || typeCoffee3 == 'M')) || ((strengthPref == 'r'
           || strengthPref == 'R') && (typeCoffee3 == 'r' || typeCoffee3 == 'R'))
           , (dailyServ > 0 && dailyServ < 5 && bagWtCoffee3 == 250) || (dailyServ > 4
           && dailyServ < 10 && bagWtCoffee3 == 500) || (dailyServ > 9 && bagWtCoffee3 == 1000)
           , ((creamPref == 'y'|| creamPref == 'Y') && (creamCoffee3 == 'y'
           || creamCoffee3 == 'Y')) || ((creamPref == 'n' || creamPref == 'N')
           && (creamCoffee3 == 'n' || creamCoffee3 == 'N')));
    

    printf("Hope you found a product that suits your likes!\n");


    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/