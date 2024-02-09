#include <stdio.h>

int pertenceFibonacci(int num)
{
    int a = 0, b = 1, c;

    if (num == 0 || num == 1)
    {
        return 1; // Pertence à sequência de Fibonacci
    }

    while (a + b <= num)
    {
        c = a + b;
        if (c == num)
        {
            return 1;
        }
        a = b;
        b = c;
    }

    return 0;

int main()
{
    int numero;

    printf("Informe um numero: ");
    scanf("%d", &numero);

    if (pertenceFibonacci(numero))
    {
        printf("%d pertence a sequencia de Fibonacci.\n", numero);
    } else
    {
        printf("%d nao pertence a sequencia de Fibonacci.\n", numero);
    }

    return 0;
}
