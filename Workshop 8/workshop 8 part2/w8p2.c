/*<assessment example name: Workshop- #8(part -2)
Full name : Kabir Narula
Student id#: 127962223
Email : knarula9@myseneca.ca
Section : NAA
Authenticity Declartion:
I Declare this submission is the result of my own work and has not been
shared with any other student or third party provider. This submitted
piece of work is enitrely of my own creation*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "w8p2.h"
int getIntPositive(int* int_ptr) {
	int input;
	int flag = 1;

	do {
		scanf("%d", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	if (int_ptr != NULL)
	{
		*int_ptr = input;
	}
	return input;
}


double getDoublePositive(double* double_ptr) {
	double input;
	int flag = 1;

	do {
		scanf("%lf", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	if (double_ptr != NULL)
	{
		*double_ptr = input;
	}
	return input;
}

void openingMessage(const int seq_number) {

	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_NUMBER);
	printf("\n");
}


struct CatFoodInfo getCatFoodInfo(const int seq_number) {
	struct CatFoodInfo cfi;
	int flag;
	printf("Cat Food Product #%d\n", seq_number + 1);
	printf("--------------------\n");
	flag = 1;

	
	printf("SKU           : ");
	flag = 1;
	do {
		scanf("%d", &cfi.skuNumber);
		if (cfi.skuNumber <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	printf("PRICE         : $");
	flag = 1;
	do {
		scanf("%lf", &cfi.productPrice);
		if (cfi.productPrice <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);


	printf("WEIGHT (LBS)  : ");
	flag = 1;
	do {
		scanf("%lf", &cfi.productWeight);
		if (cfi.productWeight <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	
	printf("CALORIES/SERV.: ");
	flag = 1;
	do {
		scanf("%d", &cfi.calories);
		if (cfi.calories <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	printf("\n");

	return cfi;

}


void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}


void displayCatFoodData(int sku_number, double* product_price, int calorie_per_serving, double* product_weight_lbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_number, *product_price, *product_weight_lbs, calorie_per_serving);
}

// ----------------------------------------------------------------------------
// PART-2

double convertLbsKg(const double* pounds, double* conversionResultToKg) {

	double poundsToKg = (*pounds) / POUNDSTOKG;

	if (conversionResultToKg != NULL)
	{
		*conversionResultToKg = poundsToKg;
	}

	return poundsToKg;
}

int convertLbsG(const double* pounds, int* conversionResultToG) {

	int poundsToG = ((*pounds) / POUNDSTOKG) * 1000;

	if (conversionResultToG != NULL)
	{
		*conversionResultToG = poundsToG;
	}

	return poundsToG;
}

void convertLbs(const double* pounds, double* conversionResultToKg, int* conversionResultToG) {

	double poundsToKg = (*pounds) / POUNDSTOKG;
	int poundsToG = ((*pounds) / POUNDSTOKG) * 1000;

	if (conversionResultToG != NULL && conversionResultToKg != NULL)
	{
		*conversionResultToG = poundsToG;
		*conversionResultToKg = poundsToKg;
	}
}

double calculateServings(const int servingSizeGrams, const int totalGrams, double* numberOfServings) {

	double servings = ((double)totalGrams) / servingSizeGrams;

	if (numberOfServings != NULL)
	{
		*numberOfServings = servings;
	}

	return servings;
}

double calculateCostPerServing(const double* price, const double* numberOfServings, double* result) {

	double costPerServing = (*price) / (*numberOfServings);

	if (result != NULL)
	{
		*result = costPerServing;
	}

	return costPerServing;
}

double calculateCostPerCal(const double* price, const double* totalCalories, double* result) {

	double costPerCal = (*price) / (*totalCalories);

	if (result != NULL)
	{
		*result = costPerCal;
	}

	return costPerCal;
}

struct ReportData calculateReportData(struct CatFoodInfo cfi) {

	struct ReportData rd;

	rd.skuNumber = cfi.skuNumber;
	rd.productPrice = cfi.productPrice;
	rd.productWeightPounds = cfi.productWeight;
	rd.calories = cfi.calories;


	rd.productWeightKilos = convertLbsKg(&rd.productWeightPounds, &rd.productWeightKilos);
	rd.productWeightGrams = convertLbsG(&rd.productWeightPounds, &rd.productWeightGrams);
	rd.servings = calculateServings(GRAMS_NUMBER, rd.productWeightGrams, &rd.servings);

	
	double totalCalories = rd.calories * rd.servings;

	rd.costPerServing = calculateCostPerServing(&rd.productPrice, &rd.servings, &rd.costPerServing);
	rd.costCaloriesPerServing = calculateCostPerCal(&rd.productPrice, &totalCalories, &rd.costCaloriesPerServing);


	return rd;
}


void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_NUMBER);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}


void displayReportData(const struct ReportData rd, const int cheapestProductCheck) {

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rd.skuNumber, rd.productPrice, rd.productWeightPounds, rd.productWeightKilos, rd.productWeightGrams, rd.calories, rd.servings, rd.costPerServing, rd.costCaloriesPerServing);
}

void displayFinalAnalysis(const struct CatFoodInfo cfi) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cfi.skuNumber, cfi.productPrice);
	printf("\n");

	
	printf("Happy shopping!\n");
	printf("\n");
}


void start(void)
{
	
	struct ReportData rd[MAX_PRODUCTS] = { {0} };
	struct CatFoodInfo cfi[MAX_PRODUCTS] = { {0} };


	int i, cheapestIndex = 0;

	openingMessage(MAX_PRODUCTS);


	for (i = 0; i < MAX_PRODUCTS; i++) {
		cfi[i] = getCatFoodInfo(i);
		rd[i] = calculateReportData(cfi[i]);
	}


	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCTS; i++) {
		displayCatFoodData(cfi[i].skuNumber, &cfi[i].productPrice, cfi[i].calories, &cfi[i].productWeight);
	}


	double cheapestProductPrice = rd[0].costPerServing;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (rd[i].costPerServing <= cheapestProductPrice)
		{
			cheapestProductPrice = rd[i].costPerServing;
			cheapestIndex = i;
		}
	}
	printf("\n");

	
	displayReportHeader();


	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayReportData(rd[i], cheapestIndex);

		if (cheapestIndex == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (i == cheapestIndex)
		{
			displayFinalAnalysis(cfi[i]);
		}
	}
}
