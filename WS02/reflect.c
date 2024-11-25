#include <stdio.h>

int main(void)
{
	// 1
	int a = 3;
	a++;
	printf("a = %d\n", a);

	int b = 3;
	printf("b = %d\n\n", b++);

	// 2
	float price1 = 10.11f, price3 = 10.14f; 
	double price2 = 10.11, price4 = 10.14; 
	printf("1. 10.11 = %f (as cents:%d)\n", price1, (int)(price1 * 100)); 
	printf("2. 10.11 = %lf (as cents:%d)\n", price2, (int)(price2 * 100)); 
	printf("%f\n", price1 * 100);
	printf("%.50lf\n", price2 * 100);
	printf("3. 10.14 = %f (as cents:%d)\n", price3, (int)(price3 * 100)); 
	printf("4. 10.14 = %lf (as cents:%d)\n\n", price4, (int)(price4 * 100));

	// 3
	int result, money = 2031; 
	printf("1. $%.2lf\n", money / 100); 
	printf("2. $%d\n", money / 100); 
	printf("3. $%.2lf\n", (double)money / 100); 
	printf("4. $%d\n", (double)money / 100);

	return 0;
}

