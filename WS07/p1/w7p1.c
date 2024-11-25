/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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

#define MAX_LIVES 10
#define MIN_LIVES 1

#define MAX_PATH_LEN 70
#define MIN_PATH_LEN 10
#define MULTIPLE 5

#define PATH_RATIO 0.75
#define YES 1
#define NO 0

struct PlayerInfo
{
    int lives;
    char symbol;
    int numTreasure;
    int pastPos[MAX_PATH_LEN];
};

struct GameInfo
{
    int maxMoves;
    int pathLen;
    int bombPos[MAX_PATH_LEN];
    int treasurePos[MAX_PATH_LEN];
};


int main(void)
{
    int i, j;   // iterators
    int valid;  // loop flag
    
    struct PlayerInfo player = { 0 };
    struct GameInfo game = { 0 };

    // Game Header
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");


    // Player Configuration
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    // input character symbol
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    // input number of lives
    do {
        valid = 0;  // initialize loop flag

        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        // check validity
        if (player.lives >= MIN_LIVES && player.lives <= MAX_LIVES)
        {
            valid = 1;
        }
        else
        {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        }
    } while (!valid);
    printf("Player configuration set-up is complete\n\n");


    // GAME Configuration
    printf("GAME Configuration\n");
    printf("------------------\n");

    // input path length
    do {
        valid = 0;  // initialize loop flag

        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE,
               MIN_PATH_LEN, MAX_PATH_LEN);
        scanf("%d", &game.pathLen);

        // check validity
        if (!(game.pathLen % MULTIPLE) &&
            (game.pathLen >= MIN_PATH_LEN && game.pathLen <= MAX_PATH_LEN))
        {
            valid = 1;
        }
        else
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE,
                   MIN_PATH_LEN, MAX_PATH_LEN);
        }
    } while (!valid);

    // input number of moves
    do {
        valid = 0;  // initialize loop flag

        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxMoves);

        // check validity
        if (game.maxMoves >= player.lives && 
            game.maxMoves <=(int)(PATH_RATIO * game.pathLen))
        {
            valid = 1;
        }
        else
        {
            printf("    Value must be between %d and %d\n", player.lives,
                   (int)(PATH_RATIO * game.pathLen));
        }
    } while (!valid);
    putchar('\n');


    // BOMB Placement
    printf("BOMB Placement\n");
    printf("--------------\n");

    // prompt to set bomb positions
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of %d=BOMB, and %d=NO BOMB. Space-delimit your input.\n", YES, NO);
    printf("(Example: %d %d %d %d %d) NOTE: there are %d to set!\n",
           YES, NO, NO, YES, YES, game.pathLen);

    for (i = 0; i < game.pathLen; i += MULTIPLE)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; ++j)
        {
            scanf("%d", &game.bombPos[i + j]);
        }
    }
    printf("BOMB placement set\n\n");


    // TREASURE Placement
    printf("TREASURE Placement\n");
    printf("------------------\n");

    // prompt to set treasure positions
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of %d=TREASURE, and %d=NO TREASURE. Space-delimit your input.\n", YES, NO);
    printf("(Example: %d %d %d %d %d) NOTE: there are %d to set!\n", 
           YES, NO, NO, YES, YES, game.pathLen);

    for (i = 0; i < game.pathLen; i += MULTIPLE)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; ++j)
        {
            scanf("%d", &game.treasurePos[i + j]);
        }
    }
    printf("TREASURE placement set\n\n");

    // reset position history
    for (i = 0; i < game.pathLen; ++i)
    {
        player.pastPos[i] = 0;
    }

    // completee the set-up process
    printf("GAME configuration set-up is complete...\n\n");


    // Summary
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    // player info
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    // game info
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLen);

    printf("   Bombs      : ");
    for (i = 0; i < game.pathLen; ++i)
    {
        printf("%d", game.bombPos[i]);
    }
    putchar('\n');
    
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLen; ++i)
    {
        printf("%d", game.treasurePos[i]);
    }
    putchar('\n');
    putchar('\n');

    // End of setting
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");


    return 0;
}
