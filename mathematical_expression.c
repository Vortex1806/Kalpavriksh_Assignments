#include <stdio.h>
long long compute(long long B, long long N, long long M)
{
    long long result = 1;
    while (N > 0)
    {
        if (N % 2 == 1)
        {
            result = (result * B) % M;
            N = N - 1;
        }
        else
        {
            N = N / 2;
            B = (B * B) % M;
        }
    }
    return result;
}
int main()
{
    long long B, N, M;
    printf("Enter the base value: ");
    scanf("%lld", &B);
    if (B < 0)
    {
        printf("\nEnter a valid base value: ");
        return -1;
    }

    printf("\n\nEnter the exponent value: ");
    scanf("%lld", &N);
    if (N < 0)
    {
        printf("\nEnter a valid exponent value: ");
        return -1;
    }

    printf("\n\nEnter the modulus value: ");
    scanf("%lld", &M);
    if (M < 1)
    {
        printf("\nEnter a valid modulus value: ");
        return -1;
    }
    if (M == 1)
    {
        printf("\nMod 1 will always result to 0");
    }
    if (B == 0)
    {
        printf("\nBase value 0 will always result to 0");
        return 0;
    }
    B = B % M;
    long long result = 1;
    // Normal method
    // for (long long i = 0; i < N; i++)
    // {
    //     result = (result * (B % M)) % M;
    // }

    // Fast Exponential Method
    result = compute(B, N, M);

    printf("Result: %lld\n", result);
    return 0;
}