#include <stdio.h>

int greatestCommonDivisor(int num1, int num2)
    {
        while(num2 != 0)
            {
                int temp = num1 % num2;

                num1 = num2;

                num2 = temp;
            }

        return num1;
    }

int main ()
    {
        int num1, num2;

        printf("\nNhap vao so thu nhat: ");

        scanf("%d", &num1);

        printf("\nNhap vao so thu hai: ");

        scanf("%d", &num2);      

        int result = greatestCommonDivisor(num1, num2);

        printf("\nUoc chung lon nhat cua %d va %d la: %d", num1, num2, result);

        printf("\n\n");

        return 0;
    }