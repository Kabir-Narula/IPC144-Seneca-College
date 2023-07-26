/*<assessment example name: Workshop- #6(part -2)
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
#include <stdio.h>
#include <math.h>
#define MAX_ITEMS 10

int main(void)
{

const double min_net_income = 500.00;
const double max_net_income = 400000.00;
const double min_cost_value = 100.00;
double tot_net_income = 0.0;
int Wish_List_Items, i, options, prior;
double monthly_income,Total_Cost_Value;
int year, month;

double Cost_Value[MAX_ITEMS];
int Item_Priority[MAX_ITEMS];
char Finance_Option[MAX_ITEMS];

printf("+--------------------------+");
printf("\n+   Wish List Forecaster   |");
printf("\n+--------------------------+");
do
{
printf("\n\nEnter your monthly NET income: $");
scanf("%lf", &monthly_income);
if(monthly_income < min_net_income)
printf("ERROR: You must have a consistent monthly income of at least $500.00");
else if(monthly_income > max_net_income)
printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");
}while(monthly_income < min_net_income || monthly_income > max_net_income);

do
{
printf("\nHow many wish list items do you want to forecast?: ");
scanf("%d", &Wish_List_Items);
if(Wish_List_Items < 1 || Wish_List_Items > MAX_ITEMS)
printf("ERROR: List is restricted to between 1 and 10 items.\n");
else
{
for(i=0;i < Wish_List_Items;i++)
{
printf("\nItem-%d Details:", i+1);
do
{
printf("\n   Item cost: $");
scanf("%lf", &Cost_Value[i]);
if(Cost_Value[i] < min_cost_value)
printf("      ERROR: Cost must be at least $100.00");
}while(Cost_Value[i] < min_cost_value);

do
{

printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
scanf("%d", &Item_Priority[i]);
if(Item_Priority[i] < 1 || Item_Priority[i] > 3)
printf("      ERROR: Value must be between 1 and 3\n");
}while(Item_Priority[i] < 1 || Item_Priority[i] > 3);

do
{
printf("   Does this item have financing options? [y/n]: ");
scanf(" %c", &Finance_Option[i]);

if(Finance_Option[i] != 'y' && Finance_Option[i] != 'n')
printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
}while(Finance_Option[i] != 'y' && Finance_Option[i] != 'n');
}
}
}while(Wish_List_Items < 1 || Wish_List_Items > MAX_ITEMS);

printf("\nItem Priority Financed        Cost");   //prints result
printf("\n---- -------- -------- -----------");
for(i=0;i < Wish_List_Items;i++)
printf("\n%3d  %5d    %5c    %11.2lf",i+1, Item_Priority[i], Finance_Option[i], Cost_Value[i]);
printf("\n---- -------- -------- -----------\n");

Total_Cost_Value = 0;
for(i=0;i < Wish_List_Items;i++)
Total_Cost_Value += Cost_Value[i];
printf("                      $%11.2lf\n\n", Total_Cost_Value);

do
{

printf("How do you want to forecast your wish list?\n 1. All items (no filter)\n 2. By priority\n 0. Quit/Exit\nSelection: ");
scanf("%d", &options);

if(options == 1)
{
printf("\n====================================================");
printf("\nFilter:   All items\n");
printf("Amount:   $%1.2lf\n", Total_Cost_Value);
month = (Total_Cost_Value + monthly_income - 1) / monthly_income;
year = month / 12;
month = month % 12;
printf("Forecast: %d years, %d months\n", year, month);
printf("NOTE: Financing options are available on some items.\n");
printf("      You can likely reduce the estimated months.\n");
printf("====================================================\n");

}

else if(options == 2) //if it is2 then read priority from the user
{
tot_net_income = 0.0;
printf("\nWhat priority do you want to filter by? [1-3]: ");
scanf("%d", & prior);
if(prior == 1)
{
for(i=0;i <Wish_List_Items;i++)
if(Item_Priority[i] == 1)
tot_net_income += Cost_Value[i];
printf("\n====================================================");
printf("\nFilter:   by priority (1)\n");
printf("Amount:   $%1.2lf\n", tot_net_income);
month = (tot_net_income + monthly_income - 1) / monthly_income;
year = month / 12;
month = month % 12;
printf("Forecast: %d years, %d months\n", year, month);
printf("NOTE: Financing options are available on some items.\n");
printf("      You can likely reduce the estimated months.\n");
printf("====================================================\n");
}

else if(prior == 2)
{
for(i=0;i <Wish_List_Items;i++)
if(Item_Priority[i] == 2)
tot_net_income += Cost_Value[i];
printf("\n====================================================");
printf("\nFilter:   by priority (2)\n");
printf("Amount:   $%1.2lf\n", tot_net_income);
month = (tot_net_income + monthly_income - 1) / monthly_income;
year = month / 12;
month = month % 12;
printf("Forecast: %d years, %d months\n", year, month);
printf("NOTE: Financing options are available on some items.\n");
printf("      You can likely reduce the estimated months.\n");
printf("====================================================\n");

}
else if(prior == 3)
{
for(i=0;i < Wish_List_Items;i++)
if(Item_Priority[i] == 3)
tot_net_income += Cost_Value[i];
printf("\n====================================================");
printf("\nFilter:   by priority (3)\n");
printf("Amount:   $%1.2lf\n", tot_net_income);
month = (tot_net_income + monthly_income - 1) / monthly_income;
year = month / 12;
month = month % 12;

printf("NOTE: Financing options are available on some items.\n");
printf("      You can likely reduce the estimated months.\n");
printf("====================================================\n");
}
}
//print error if the inavlid options
else if( options < 0 || options > 2)
printf("\nERROR: Invalid menu selection.\n");
printf("\n");
}while(options != 0);
printf("Best of luck in all your future endeavours!\n");
return 0;

}