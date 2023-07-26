#define _CRT_SECURE_NO_WARNINGS
#define MIN_LIVE 1
#define MAX_LIVE 10
#define MIN_PATH 10
#define MAX_PATH 70
#define MIN_LIMIT 3
#define MAX_LIMIT 15
#define MIN_MOVE 1

#include <stdio.h>


struct PlayerInfo
{
    char Character;
    int Lives;
};

struct GameInfo
{
    int Path;     // use const
    int Bomb[MAX_PATH];
    int Treasure[MAX_PATH];
    int Limit;
};

struct DuringTheGame
{
    int TreasureOnTheGame;
    char Trial[MAX_PATH];
    int TreasureCurrent;
};

int main(void)
{
    int whiteflag = 0;
    int blueflag = 0;
    int greenflag = 1;
    int i;
    int j = 1;
    int nrows, mrows;


    struct PlayerInfo Player;
    struct GameInfo Game;
    struct DuringTheGame Start;


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &Player.Character);


    // Set lives
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &Player.Lives);

        if (Player.Lives < MIN_LIVE || Player.Lives > MAX_LIVE)
            printf("     Must be between %d and %d!\n", MIN_LIVE, MAX_LIVE);

        else
            whiteflag = 1;

    } while (whiteflag == 0);

    printf("Player configuration set-up is complete\n");
    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    // Set path
    do
    {
        printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_PATH, MAX_PATH);
        scanf("%d", &Game.Path);
        if (Game.Path % 5 != 0 || Game.Path < MIN_PATH || Game.Path > MAX_PATH)
            printf("     Must be a multiple of 5 and between %d-%d!!!\n", MIN_PATH, MAX_PATH);

        else
            whiteflag = 0;

    } while (whiteflag == 1);

    // Set moves
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &Game.Limit);

        if (Game.Limit < MIN_LIMIT || Game.Limit > MAX_LIMIT)
            printf("    Value must be between %d and %d\n", MIN_LIMIT, MAX_LIMIT);
        else
            whiteflag = 1;

    } while (whiteflag == 0);

    // BOMB PLACEMENT
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.Path);


    nrows = Game.Path / 5;
    for (i = 0; i < nrows; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &Game.Bomb[(i * 5 + j)]);
        }

    }
    printf("BOMB placement set\n\n");


    // TREASURE PLACEMENT
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %2d to set!\n", Game.Path);

    mrows = Game.Path / 5;
    for (i = 0; i < mrows; i++)
    {
        /*     if ( i == 1)
             printf("     Positions [ %d- %d]: ", (i * 5) + 1, (i * 5) + 5);

             else if (i == 2)
             printf("     Positions [ %d-%d]: ", (i * 5) + 1, (i * 5) + 5);

             else if (i > 2)
             printf("     Positions [%d-%d]: ", (i * 5) + 1, (i * 5) + 5);

             scanf("%d %d %d %d %d", &Game.Treasure[i * 5 - 5], &Game.Treasure[i * 5 - 4], &Game.Treasure[i * 5 - 3], &Game.Treasure[i * 5 - 2], &Game.Treasure[i * 5 - 1]);*/

        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &Game.Treasure[(i * 5 + j)]);
        }

    }

    printf("TREASURE placement set\n\n");


    // Game configuration set up
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", Player.Character);
    printf("   Lives      : %d\n", Player.Lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", Game.Path);
    printf("   Bombs      : ");
    for (i = 0; i < Game.Path; i++)
    {
        printf("%d", Game.Bomb[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < Game.Path; i++)
    {
        printf("%d", Game.Treasure[i]);
    }


    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");



    Start.TreasureCurrent = 0;
    for (i = 1; i <= Game.Path; i++)
    {
        Start.Trial[i] = '-';
    }

    do
    {
        while (blueflag == 1)
        {
            do
            {
                printf("  ");
            } while (blueflag == 0);
            for (i = 1; i <= j; i++)
            {
                if (j == i)
                {
                    printf("%c", Player.Character);

                }
                else
                {
                    printf(" ");
                }
            }
            blueflag = 0;
        }
        printf("\n  ");

        for (i = 1; i <= Game.Path; i++)
        {
            printf("%c", Start.Trial[i]);
        }
        printf("\n  ");

        for (i = 1; i <= Game.Path; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n  ");

        for (i = 1; i <= Game.Path; i++)
        {
            if (i > 9)
            {
                greenflag = i / 10;
                printf("%d", i - (greenflag * 10));
            }
            else
            {
                printf("%d", i);
            }
        }
        greenflag = 1;

        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", Player.Lives, Start.TreasureCurrent, Game.Limit);
        printf("+---------------------------------------------------+\n");
        whiteflag = 1;
        if ((Game.Limit != 0) && (Player.Lives != 0))
        {
            do
            {
                printf("Next Move [1-%d]: ", Game.Path);
                scanf("%2d", &j);

                blueflag = 1;
                if (j > Game.Path || j < 1)
                {
                    printf("  Out of Range!!!\n");
                }
                else
                {
                    whiteflag = 0;
                }
            } while (whiteflag == 1);

            if (Start.Trial[j] != '-')
            {
                printf("\n===============> Dope! You've been here before!\n\n");
            }

            else if (Game.Bomb[j - 1] == 1 && Game.Treasure[j - 1] == 1)
            {
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                Start.Trial[j] = '&';
                Game.Limit--;
                Player.Lives--;
                Start.TreasureCurrent++;
            }

            else if (Game.Bomb[j - 1] == 1)
            {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
                Start.Trial[j] = '!';
                Game.Limit--;
                Player.Lives--;
            }

            else if (Game.Treasure[j - 1] == 1)
            {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                Start.Trial[j] = '$';
                Game.Limit--;
                Start.TreasureCurrent++;
            }

            else
            {
                printf("\n===============> [.] ...Nothing found here... [.]\n\n");
                Start.Trial[j] = '.';
                Game.Limit--;
            }

            if (Player.Lives == 0)
            {
                printf("No more LIVES remaining!\n\n");
            }

            else if (Game.Limit == 0)
            {
                printf("No more MOVES remaining!\n\n");
            }

        }
        else
        {
            printf("\n");
            printf("##################\n");
            printf("#   Game over!   #\n");
            printf("##################\n");
            greenflag = 0;
        }

    } while (greenflag == 1);

    // Endgame 
    printf("\nYou should play again and try to beat your score!\n");

    return 0;
}