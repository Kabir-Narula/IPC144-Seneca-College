/*<assessment example name: Workshop- #6(part -1)
Full name : Kabir Narula
Student id#: 127962223
Email : knarula9@myseneca.ca
Section : NAA
Authenticity Declartion:
I Declare this submission is the result of my own work and has not been
shared with any other student or third party provider. This submitted
piece of work is enitrely of my own creation*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<stdio.h>
#include<string.h>
#define maxitems 10
int main(void) {
   int priority[10], items, i;       //declaring integer priority array and other variables
    char a[10];                              //declaring a char array for financing options
    float cost[10], income;
    double sum = 0;//declaring float array cost and other variables
    const int maximum = 400000, minimum = 500;    //declaring unmodifiable variables maximum and minimum
    printf("+--------------------------+");
    printf("\n+   Wish List Forecaster   |");
    printf("\n+--------------------------+");
    do {                                       //iteration construct to check income limits
        printf("\n\nEnter your monthly NET income: $");
        scanf("%f", &income);
        if (income < minimum)
            printf("ERROR: You must have a consistent monthly income of at least $500.00");
        else if (income > maximum)
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");
    } while (income < 500 || income>400000);
    do {                                       //iteration construct to check number of items
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &items);
        if (items<1 || items>maxitems)
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
    } while (items<1 || items>maxitems);
    for (i = 0; i < items; i++)
    {
        printf("\nItem-%d Details:", i + 1);
        do {
            printf("\n   Item cost: $");
            scanf("%f", &cost[i]);
            if (cost[i] < 100.0)
                printf("      ERROR: Cost must be at least $100.00");
        } while (cost[i] < 100.0);
        do { //iteration construct to get correct priority of item
            //iteration construct to get correct priority of item
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] != 1 && priority[i] != 2 && priority[i] != 3)
                printf("      ERROR: Value must be between 1 and 3\n");
        } while (priority[i] < 1 || priority[i]>3);
        do {              
            scanf("%c", &a[i]);//iteration construct to get financing option for item
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%c", &a[i]);
            if (a[i] != 'y' && a[i] != 'n')
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        } while (a[i] != 'y' && a[i] != 'n');
    }

    printf("\nItem Priority Financed        Cost");   //prints result
    printf("\n---- -------- -------- -----------");
    for (i = 0; i < items; i++) {
        printf("\n%3d  %5d    %5c    %11.2lf", i + 1, priority[i], a[i], cost[i]);
        sum = sum + cost[i];
    }

    printf("\n---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sum);
    printf("Best of luck in all your future endeavours!\n");                          
    return 0;

}
