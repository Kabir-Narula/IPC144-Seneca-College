#define _CRT_SECURE_NO_WARNINGS

#define MAXIMUM_PATH_LENGTH 70
#define MINIMUM_PATH_LENGTH 10
#define MAXIMUM_LIVES 10
#define MINIMUM_LIVES 1
#define MULTIPLE 5
#include <stdio.h>

struct Info {
    int lives;
    char Character;
    int treasureCount;
    int positionHistory[MAXIMUM_PATH_LENGTH];
};

struct game {
    int moves;
    int bombLocations[MAXIMUM_PATH_LENGTH];
    int Locations[MAXIMUM_PATH_LENGTH];
    int Length;
};

int main(void)
{
    int i, j, k; 
    struct Info player;
    struct game game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.Character);

    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        if (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES);

    printf("Player configuration set-up is complete\n");
    printf("\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.Length);

        if ((game.Length < MINIMUM_PATH_LENGTH || game.Length > MAXIMUM_PATH_LENGTH) || (game.Length % MULTIPLE != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while ((game.Length < MINIMUM_PATH_LENGTH || game.Length > MAXIMUM_PATH_LENGTH) || (game.Length % MULTIPLE != 0));

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);

        if (game.moves < player.lives || game.moves >(int) (0.75 * game.Length))
        {
            printf("    Value must be between %d and %d\n", player.lives, (int)(0.75 * game.Length));
        }
    } while (game.moves < player.lives || game.moves >(int) (0.75 * game.Length));
    printf("\n");

  
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < game.Length; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombLocations[i], &game.bombLocations[i + 1], &game.bombLocations[i + 2], &game.bombLocations[i + 3], &game.bombLocations[i + 4]);
    }

    printf("BOMB placement set\n");
    printf("\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");


    for (i = 0; i < game.Length; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.Locations[i], &game.Locations[i + 1], &game.Locations[i + 2], &game.Locations[i + 3], &game.Locations[i + 4]);
    }

    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n");
    printf("\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.Character);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    // Game Details
    printf("Game:\n");
    printf("   Path Length: %d\n", game.Length);

    printf("   Bombs      : ");
    for (j = 0; j < game.Length; j++)
    {
        printf("%d", game.bombLocations[j]);
    }
    printf("\n");

    printf("   Treasure   : ");
    for (k = 0; k < game.Length; k++)
    {
        printf("%d", game.Locations[k]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    printf("\n");

    return 0;
}