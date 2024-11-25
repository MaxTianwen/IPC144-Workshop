/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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
    char loopType;
    int loopTimes;

    int i; // The iterator in loops
    int continueLoop;   // The condition of the main loop


    // Print the start title
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");


    // Iteration part
    do {
        // Get input from user
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &loopTimes);

        continueLoop = 1;   // Initialize the main loop condition

        if ((loopType == 'W' || loopType == 'D' || loopType == 'F') && 
            (loopTimes < 3 || loopTimes > 20))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }
        else
        {
            switch (loopType)
            {
            case 'W':
                break;

            }
        }
        // Do while loop
        if (loopType == 'D')
        {
            if (loopTimes > 2 && loopTimes < 21)
            {
                printf("DO-WHILE: ");
                i = 0;
                do {
                    printf("%c", loopType);
                    ++i;
                } while (i < loopTimes);
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        // While loop
        else if (loopType == 'W')
        {
            if (loopTimes > 2 && loopTimes < 21)
            {
                printf("WHILE   : ");
                i = 0;
                while (i < loopTimes)
                {
                    printf("%c", loopType);
                    ++i;
                }
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        // For loop
        else if (loopType == 'F')
        {
            if (loopTimes > 2 && loopTimes < 21)
            {
                printf("FOR     : ");
                i = 0;
                for (i = 0; i < loopTimes; i++)
                {
                    printf("%c", loopType);
                }
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        // Quit loop with a wrong input number
        else if (loopType == 'Q')
        {
            if (loopTimes == 0)
            {
                continueLoop = 0;
                printf("\n");
            }
            else
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            }
        }
        // Input with a undefined letter
        else
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
    } while (continueLoop);


    // Print the end title
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");


    return 0;
}
