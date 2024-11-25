/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_RATING 0.0
#define MAX_RATING 5.0
#define LOG_DAYS 3


int main(void)
{
    const int JAN = 1, DEC = 12;

    int year, month;
    double morningRat, eveningRat;
    double morningTotalRat = 0, eveningTotalRat = 0;

    int i;  // Iterator of days
    int valid;  // Set flags for existing loops


    // Print the start title
    printf("General Well-being Log\n");
    printf("======================\n");


    // Part 1: set year and month
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

    // Part 1 end
    printf("\n");
    printf("*** Log date set! ***\n\n");


    // Part 2
    // Map month integer to 3-characters and print
    for (i = 0; i < LOG_DAYS; ++i)
    {
        // print the first common part
        printf("%d-", year);

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
        printf("-%02d\n", i + 1);

        // Get morning input
        do {
            // Initialize the flag
            valid = 0;

            printf("   Morning rating (%.1lf-%.1lf): ", MIN_RATING, MAX_RATING);
            scanf("%lf", &morningRat);

            if (morningRat < MIN_RATING || morningRat > MAX_RATING)
            {
                printf("      ERROR: Rating must be between %.1lf and %.1lf inclusive!\n"
                       , MIN_RATING, MAX_RATING);
            }
            else
            {
                morningTotalRat += morningRat;
                valid = 1;
            }
        } while (!valid);

        // Get evening input
        do {
            // Initialize the flag
            valid = 0;

            printf("   Evening rating (%.1lf-%.1lf): ", MIN_RATING, MAX_RATING);
            scanf("%lf", &eveningRat);

            if (eveningRat < MIN_RATING || eveningRat > MAX_RATING)
            {
                printf("      ERROR: Rating must be between %.1lf and %.1lf inclusive!\n"
                       , MIN_RATING, MAX_RATING);
            }
            else
            {
                eveningTotalRat += eveningRat;
                valid = 1;
            }
        } while (!valid);
        printf("\n");
    }

    // Summary
    // Title
    printf("Summary\n");
    printf("=======\n");

    // Total rating
    printf("Morning total rating: %6.3lf\n", morningTotalRat);
    printf("Evening total rating: %6.3lf\n", eveningTotalRat);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n\n", morningTotalRat + eveningTotalRat);

    // Average rating
    printf("Average morning rating: %4.1lf\n", morningTotalRat / LOG_DAYS);
    printf("Average evening rating: %4.1lf\n", eveningTotalRat / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", (morningTotalRat + eveningTotalRat)
           / (LOG_DAYS * 2));

    return 0;
}