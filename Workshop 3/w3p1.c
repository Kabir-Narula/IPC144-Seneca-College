/*<assessment example name: Workshop- #3(part -1)

Authenticity Declartion:
I Declare this submission is the result of my own work and has not been
shared with any other student or third party provider. This submitted
piece of work is enitrely of my own creation*/
#include <stdio.h>
int main(void)
{
	int productid1, productid2, productid3;
	double product1price, product2price, product3price, average;
	char product1tax, product2tax, product3tax;
	const double testvalue = 330.99;
	productid1 = 111, productid2 = 222, productid3 = 111;
	product1price = 111.4900, product2price = 222.9900, product3price = 334.4900;
	product1tax = 'Y'; product2tax = 'N', product3tax = 'N';
	average = 222.9900;
	printf("Product Information\n");
	printf("===================\n");
	printf("Product-1 (ID:%d)\n", productid1);
	printf("  Taxed: %c\n", product1tax);
	printf("  Price: $%8.4lf\n", product1price);
	printf("\n");
	printf("Product-2 (ID:%d)\n", productid2);
	printf("  Taxed: %c\n", product2tax);
	printf("  Price: $%8.4lf\n", product2price);
	printf("\n");
	printf("Product-3 (ID:%d)\n", productid3);
	printf("  Taxed: %c\n", product3tax);
	printf("  Price: $%8.4lf\n", product3price);
	printf("\n");
	printf("The average of all prices is: $%4.4lf\n", average);
	printf("\n");
	printf("About Relational and Logical Expressions!\n");
	printf("========================================\n");
	printf("1. These expressions evaluate to TRUE or FALSE\n");
	printf("2. FALSE: is always represented by integer value 0\n");
	printf("3. TRUE : is represented by any integer value other than 0\n");
	printf("\n");
	printf("Some Data Analysis...\n");
	printf("=====================\n");
	printf("1. Is product 1 taxable? -> %d\n\n", product1tax == 'Y');
	printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n",
		(product2tax == 'N') && (product3tax == 'N'));
	printf("3. Is product 3 less than testValue ($%4.2lf)? -> %d\n\n", testvalue, product3price < testvalue);
	printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", (product3price) > (product1price + product2price));
	printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d", (product1price) >= (product3price - product2price)),
	printf(" (price difference: $%3.2lf)\n\n",(product3price - product2price));
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", product2price >= average);
	printf("7. Based on product ID, product 1 is unique -> %d\n\n", (productid1 != productid2) && (productid1 != productid3));
	printf("8. Based on product ID, product 2 is unique -> %d\n\n", (productid2 != productid1) && (productid2 != productid3));
	printf("9. Based on product ID, product 3 is unique -> %d\n\n", (productid3 != productid2) && (productid3 != productid1));
	return(0);
}





