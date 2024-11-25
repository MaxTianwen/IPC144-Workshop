/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022


int main(void)
{
    const int JAN = 1, DEC = 12;

    int year, month;
    //int validYear, validMonth;  // Set flags for the iteration
    int valid;


    // Print the title
    printf("General Well-being Log\n");
    printf("======================\n");

    //do {
    //    validYear = 0, validMonth = 0;  // Initialize the flag

    //    // Get input from user
    //    printf("Set the year and month for the well-being log (YYYY MM): ");
    //    scanf("%d%d", &year, &month);

    //    // Check input year
    //    if (year < MIN_YEAR || year > MAX_YEAR)
    //    {
    //        printf("   ERROR: The year must be between %d and %d inclusive\n", 
    //               MIN_YEAR, MAX_YEAR);
    //    }
    //    else
    //    {
    //        validYear = 1;
    //    }

    //    // Check input month
    //    if (month < JAN || month > DEC)
    //    {
    //        printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
    //    }
    //    else
    //    {
    //        validMonth = 1;
    //    }
    //} while (!validYear || !validMonth);


    do {
        valid = 1;  // Initialize the flag

        // Get input from user
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d", &year, &month);

        // Check input year
        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n",
                MIN_YEAR, MAX_YEAR);
            valid = 0;
        }

        // Check input month
        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
            valid = 0;
        }
    } while (!valid);

    // End title
    printf("\n");
    printf("*** Log date set! ***\n\n");

    // Print the first common part
    printf("Log starting date: %d-", year);

    // Map month integer to 3-characters and output the result
    switch (month)
    {
    case 1:
            printf("JAN");
            break;   
    case 2:
            printf("FEB");
            break;    
    case 3:
            printf("MAR");
            break;    
    case 4:
            printf("APR");
            break;   
    case 5:
            printf("MAY");
            break;    
    case 6:
            printf("JUN");
            break;    
    case 7:
            printf("JUL");
            break;   
    case 8:
            printf("AUG");
            break;    
    case 9:
            printf("SEP");
            break;    
    case 10:
            printf("OCT");
            break;   
    case 11:
            printf("NOV");
            break;    
    case 12:
            printf("DEC");
            break;
    }

    // Print the last common part
    printf("-01\n");

    return 0;
}