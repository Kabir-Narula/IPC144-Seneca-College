#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

#include "w8p1.h"


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

	// Calories
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

	// Returning the struct
	return cfi;

}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku_number, double* product_price, int calorie_per_serving, double* product_weight_lbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_number, *product_price, *product_weight_lbs, calorie_per_serving);
}

// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo cfi[MAX_PRODUCTS] = { {0} };
	openingMessage(MAX_PRODUCTS);

	for (i = 0; i < MAX_PRODUCTS; i++) {
		cfi[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCTS; i++) {
		displayCatFoodData(cfi[i].skuNumber, &cfi[i].productPrice, cfi[i].calories, &cfi[i].productWeight);
	}

}