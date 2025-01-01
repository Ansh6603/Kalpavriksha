#include<stdio.h>

long solvingExponent(int base, long exponent, long modulus)
{
    // If exponent is 0, the result is always 1 (base^0 = 1)
    if (exponent == 0)
    {
        return 1;
    }

    long result = 1; 

    while (exponent > 0)
    {
        // If exponent is odd : base^exponent = base * (base^(exponent - 1))
        if (exponent % 2 == 1) 
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        // The exponent is reduced by half in each iteration
        exponent = exponent / 2;
    }

    return result;
}

int main()
{
    int base;
    long exponent, modulus;

    printf("Enter the base B\n");
    scanf("%d", &base);
    printf("Enter the exponent N\n");
    scanf("%ld", &exponent);
    printf("Enter the Modulus M\n");
    scanf("%ld", &modulus);

    if (modulus <= 1)
    {
        printf("Error: Modulus must be greater than 1\n");
        return 1;  
    }

    if (exponent < 0)
    {
        printf("Error: Exponent must be greater than or equal to 0\n");
        return 1;  
    }

    long result = solvingExponent(base, exponent, modulus);
    printf("Result: %ld\n", result);

    return 0;  
}
