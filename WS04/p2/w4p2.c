/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Tianwen Wang
Student ID#: 151583226
Email      : twang118@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages;
    int pickApples, pickOranges, pickPears, pickTomatoes, pickCabbages;

    int continueLoop;
    int shoppingAgain;   // The flag for restarting the shopping process


    // Main loop entrance
    do {
        // Shopping
        // Title
        printf("Grocery Shopping\n");
        printf("================\n");

        // Input the numbers of shopping items
        // Apples
        continueLoop = 1;
        do {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                continueLoop = 0;
                printf("\n");
            }
        } while (continueLoop);

        // Oranges
        continueLoop = 1;
        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                continueLoop = 0;
                printf("\n");
            }
        } while (continueLoop);

        // pears
        continueLoop = 1;
        do {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);

            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                continueLoop = 0;
                printf("\n");
            }
        } while (continueLoop);

        // Tomatoes
        continueLoop = 1;
        do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);

            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                continueLoop = 0;
                printf("\n");
            }
        } while (continueLoop);

        // Cabbages
        continueLoop = 1;
        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                continueLoop = 0;
                printf("\n");
            }
        } while (continueLoop);


        // Pick items
        // Title
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        // Apples
        if (apples != 0)
        {
            continueLoop = 1;
            do {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickApples);

                if (pickApples < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    if (pickApples == apples)
                    {
                        continueLoop = 0;
                        printf("Great, that's the apples done!\n");
                    }
                    else if (pickApples > apples)
                    {
                        printf("You picked too many... only %d more APPLE(S) are needed.\n",
                            apples);
                    }
                    else if (pickApples < apples)
                    {
                        apples -= pickApples;
                        printf("Looks like we still need some APPLES...\n");
                    }
                }
            } while (continueLoop);
            printf("\n");
        }

        // Oranges
        if (oranges != 0)
        {
            continueLoop = 1;
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickOranges);

                if (pickOranges < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    if (pickOranges == oranges)
                    {
                        continueLoop = 0;
                        printf("Great, that's the oranges done!\n");
                    }
                    else if (pickOranges > oranges)
                    {
                        printf("You picked too many... only %d more ORANGE(S) are needed.\n",
                            oranges);
                    }
                    else if (pickOranges < oranges)
                    {
                        oranges -= pickOranges;
                        printf("Looks like we still need some ORANGES...\n");
                    }
                }
            } while (continueLoop);
            printf("\n");
        }

        // Pears
        if (pears != 0)
        {
            continueLoop = 1;
            do {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickPears);

                if (pickPears < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    if (pickPears == pears)
                    {
                        continueLoop = 0;
                        printf("Great, that's the pears done!\n");
                    }
                    else if (pickPears > pears)
                    {
                        printf("You picked too many... only %d more PEAR(S) are needed.\n",
                            pears);
                    }
                    else if (pickPears < pears)
                    {
                        pears -= pickPears;
                        printf("Looks like we still need some PEARS...\n");
                    }
                }
            } while (continueLoop);
            printf("\n");
        }

        // Tomatoes
        if (tomatoes != 0)
        {
            continueLoop = 1;
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickTomatoes);

                if (pickTomatoes < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    if (pickTomatoes == tomatoes)
                    {
                        continueLoop = 0;
                        printf("Great, that's the tomatoes done!\n");
                    }
                    else if (pickTomatoes > tomatoes)
                    {
                        printf("You picked too many... only %d more TOMATO(ES) are needed.\n",
                            tomatoes);
                    }
                    else if (pickTomatoes < tomatoes)
                    {
                        tomatoes -= pickTomatoes;
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                }
            } while (continueLoop);
            printf("\n");
        }

        // Cabbages
        if (cabbages != 0)
        {
            continueLoop = 1;
            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickCabbages);

                if (pickCabbages < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    if (pickCabbages == cabbages)
                    {
                        continueLoop = 0;
                        printf("Great, that's the cabbages done!\n");
                    }
                    else if (pickCabbages > cabbages)
                    {
                        printf("You picked too many... only %d more CABBAGE(S) are needed.\n",
                            cabbages);
                    }
                    else if (pickCabbages < cabbages)
                    {
                        cabbages -= pickCabbages;
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                }
            } while (continueLoop);
            printf("\n");
        }

        // Print the end message and ask user whether to shop more
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shoppingAgain);
        
        if (shoppingAgain == 0)
        {
            printf("\n");
            printf("Your tasks are done for today - enjoy your free time!");
        }
        printf("\n");

    } while (shoppingAgain);


    return 0;
}