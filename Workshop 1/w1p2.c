#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	float s, m, l;
	float S, M, L, totalshirts;
	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter Price for small shirt: $");
	scanf_s("%f", &s);
	S = s * 100;
	printf("Enter Price for medium Shirt:$");
	scanf_s("%f", &m);
	M = m * 100;
	printf("Enter Price for small shirt: $");
	scanf_s("%f", &l);
	L = l * 100;
	printf("\n\n");
	printf("Shirt Store Price List\n");
	printf("======================\n");
	printf("Small  : $%.2f\n", ((float)S) / 100);
	printf("Medium : $%.2f\n", ((float)M) / 100);
	printf("Large  : $%.2f\n", ((float)L) / 100);
	printf("\n");
	printf("Patty's shirt size is 'S'\n");
	printf("Number of shirts Patty is buying: ");
	scanf_s("%f", &totalshirts);
	printf("\n\n");
	printf("Patty's shopping cart...");
	printf("\n");
	printf("Contains :%fshirts\n", totalshirts);
	float subtotal;
	float tax;
	tax = 0.13;
	subtotal = s * totalshirts;
	printf("Sub-total : $%f", (subtotal));
	printf("\n");
	printf("tax       : $%f", ((subtotal * tax) + 0.5) / 100);
	printf("\n");
	printf("total     : $%f", ((subtotal + (subtotal * tax) + 0.5 / 100)));
	return 0;
}