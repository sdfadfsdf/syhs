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
    printf("���� ���: %d\n", sum);
    printf("���� ���: %d\n", product);
    return 0;
}

