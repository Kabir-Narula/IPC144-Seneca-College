
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : kabir narula
Student ID#: 127962223
Email      : knarula9@myseneca.ca
Section    :NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    //VARIABLE DECLARATIONS
    const double GRAMS_IN_LBS = 453.5924;

    char type1, type2, type3, type4, type5;
    int bagWeight1, bagWeight2, bagWeight3, bagWeight4, bagWeight5;
    char cream1, cream2, cream3, cream4, cream5;


    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);
    printf("\n");

    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", type1 == type1, type1 == type2, type1 == type3, bagWeight1, bagWeight1 / GRAMS_IN_LBS, cream1 == cream1);
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", type2 == type1, type2 == type3, type2 == type2, bagWeight2, bagWeight2 / GRAMS_IN_LBS, cream2 == cream1);
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", type3 == type1, type3 == type3, type3 == type2, bagWeight3, bagWeight3 / GRAMS_IN_LBS, cream3 == cream1);
    /////////////////////////////////////////////////////////
    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &type4);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream4);
    printf("Typical number of daily servings: ");
    scanf(" %d", &bagWeight4);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|      % d         |     % d      |  % d   |\n", type4 == type4, bagWeight4 < 3, cream4 == cream4);
    printf(" 2|      % d         |     % d      |  % d   |\n", type4 == type3, bagWeight4 < 2, cream4 == cream3);
    printf(" 3|      % d         |     % d      |  % d   |\n\n", type4 == type2, bagWeight4 < 1, cream4 == cream3);
    ///////////////////////////////////////////////////////////////
    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &type5);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream5);
    printf("Typical number of daily servings: ");
    scanf(" %d", &bagWeight5);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|      % d         |     % d      |  % d   |\n", type5 == type4, bagWeight5 < 3, cream5 == cream4);
    printf(" 2|      % d         |     % d      |  % d   |\n", type5 == type4, bagWeight4 < 2, cream5 == cream5);
    printf(" 3|      % d         |     % d      |  % d   |\n\n", type5 == type5, bagWeight5 > 1, cream5 == cream5);

    printf("Hope you found a product that suits your likes!\n");
    return 0;
}
