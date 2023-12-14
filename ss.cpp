#include <stdio.h>
void add_mul(int num1, int num2, int *sum, int *product)
{
	*sum = num1 + num2;
    *product = num1 * num2;
}
int main()
{
    int num1 = 2023, num2 = 5112;
    int sum, product;
    add_mul(num1, num2, &sum, &product);
    printf("µ¡¼À °á°ú: %d\n", sum);
    printf("°ö¼À °á°ú: %d\n", product);
    return 0;
}

