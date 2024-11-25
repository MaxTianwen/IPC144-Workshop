/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

// Game setting macros
// player: numLives
#define MAX_LIVES 10
#define MIN_LIVES 1

// game: pathLen
#define MAX_PATH_LEN 70
#define MIN_PATH_LEN 10

// others
#define MULTIPLE 5
#define RATIO 0.75
#define YES 1
#define NO 0

// In game macros
// player: position nums
#define MAJOR_POS_NUM 10
#define MINOR_POS_NUM 1

// position symbols
#define UNDISCOVERED '-'
#define BOMB '!'
#define TREASURE '$'
#define BOTH '&'
#define NEITHER '.'

// others
#define MIN_MOVE 1

struct PlayerInfo
{
    int lives;
    char symbol;
    int treasures;
    int pastPos[MAX_PATH_LEN];
};

struct GameInfo
{
    int movesRemaining;
    int pathLen;
    int bombPos[MAX_PATH_LEN];
    int treasurePos[MAX_PATH_LEN];
};


int main(void)
{
    int i, j;
    int valid, gameOver;
    int moveSteps;

    struct PlayerInfo player = { 0 };
    struct GameInfo game = { 0 };

    // Part 1. Game setting
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
        scanf("%d", &game.movesRemaining);

        // check validity
        if (game.movesRemaining >= player.lives && 
            game.movesRemaining <= (int)(RATIO * game.pathLen))
        {
            valid = 1;
        }
        else
        {
            printf("    Value must be between %d and %d\n", player.lives, 
                   (int)(RATIO * game.pathLen));
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
    printf("====================================\n\n");




    // Part 2. Play game

    // Display game board
    // player location
    gameOver = 0;   // set game over flag
    moveSteps = 0;  // initialize move steps before starting game

    while (!gameOver)
    {
        if (moveSteps)
        {
            printf("  ");
            for (i = 0; i < moveSteps - 1; ++i)
            {
                putchar(' ');
            }
            printf("%c\n", player.symbol);
        }

        // location info
        printf("  ");
        for (i = 0; i < game.pathLen; ++i)
        {
            if (player.pastPos[i] == NO)
            {
                printf("%c", UNDISCOVERED);
            }
            else
            {
                if (game.bombPos[i] && game.treasurePos[i])
                {
                    printf("%c", BOTH);
                }
                else if (!game.bombPos[i] && game.treasurePos[i])
                {
                    printf("%c", TREASURE);
                }
                else if (game.bombPos[i] && !game.treasurePos[i])
                {
                    printf("%c", BOMB);
                }
                else
                {
                    printf("%c", NEITHER);
                }
            }
        }
        putchar('\n');

        // major position ruler
        printf("  ");
        for (i = 1; i <= game.pathLen; ++i)
        {
            if (i % 10)
            {
                printf("|");
            }
            else
            {
                printf("%d", i / 10);
            }
        }
        putchar('\n');

        // minor position ruler
        printf("  ");
        for (i = 1; i <= game.pathLen; ++i)
        {
            printf("%d", i % 10);
        }
        putchar('\n');

        // isplay player's statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
            player.lives, player.treasures, game.movesRemaining);
        printf("+---------------------------------------------------+\n");

        // check if game is over
        if (!player.lives || !game.movesRemaining)
        {
            gameOver = 1;
        }
        else
        {
            // input next move
            do {
                valid = 0;

                printf("Next Move [%d-%d]: ", MIN_MOVE, game.pathLen);
                scanf("%d", &moveSteps);

                // check validity of next move
                if (moveSteps < MIN_MOVE || moveSteps > game.pathLen)
                {
                    printf("  Out of Range!!!\n");
                }
                else
                {
                    valid = 1;
                }
            } while (!valid);
            putchar('\n');

            // check current location
            if (player.pastPos[moveSteps - 1])
            {
                printf("===============> Dope! You've been here before!\n\n");
            }
            else
            {
                // update history and remaining moves
                player.pastPos[moveSteps - 1] = 1;
                game.movesRemaining -= 1;

                // check treasure or bomb 
                if (game.bombPos[moveSteps - 1] && game.treasurePos[moveSteps - 1])
                {
                    // update lives, tresures, bombs
                    player.lives -= 1;
                    player.treasures += 1;
                    game.bombPos[moveSteps - 1] = 1;
                    game.treasurePos[moveSteps - 1] = 1;
                    printf("===============> [%c] !!! BOOOOOM !!! [%c]\n", BOTH, BOTH);
                    printf("===============> [%c] $$$ Life Insurance Payout!!! [%c]\n\n"
                           , BOTH, BOTH);
                }
                else if (!game.bombPos[moveSteps - 1] && game.treasurePos[moveSteps - 1])
                {
                    // update lives, tresures, bombs
                    player.treasures += 1;
                    game.treasurePos[moveSteps - 1] = 1;
                    printf("===============> [%c] $$$ Found Treasure! $$$ [%c]\n\n"
                           , TREASURE, TREASURE);
                }
                else if (game.bombPos[moveSteps - 1] && !game.treasurePos[moveSteps - 1])
                {
                    // update lives, tresures, bombs
                    player.lives -= 1;
                    game.bombPos[moveSteps - 1] = 1;
                    printf("===============> [%c] !!! BOOOOOM !!! [%c]\n\n", BOMB, BOMB);
                }
                else
                {
                    printf("===============> [%c] ...Nothing found here... [%c]\n\n"
                           , NEITHER, NEITHER);
                }

                // check if lives/moves equals 0
                if (!player.lives)
                {
                    printf("No more LIVES remaining!\n\n");
                }
                
                if (!game.movesRemaining)
                {
                    printf("No more MOVES remaining!\n\n");
                }
            }
        }
    }

    // Game Over
    putchar('\n');
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");

    return 0;
}
