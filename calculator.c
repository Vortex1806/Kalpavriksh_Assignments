#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int precedence(char op)
{
    switch (op)
    {
    case '+':
        return 1;
    case '-':
        return 0;
    case '*':
        return 2;
    case '/':
        return 3;
    }
    return -1;
}

int operation(int first_digit, int second_digit, char operator)
{
    switch (operator)
    {
    case '*':
        return first_digit * second_digit;
    case '+':
        return first_digit + second_digit;
    case '-':
        return first_digit - second_digit;
    case '/':
        if (second_digit == 0)
        {
            printf("Error dividing by zero\n");
            exit(0);
        }
        return first_digit / second_digit;
    default:
        return 0;
    }
}

int is_space(char ch)
{
    if (ch == ' ' || ch == '\n')
    {
        return 1;
    }
    return 0;
}
int is_digit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

int string_length(char *str)
{
    int size = 0;
    while (str[size] != '\0')
        size++;
    return size;
}

int evaluate(char *expression)
{
    int number_stack[MAX], number_stack_top = -1;
    char operator_stack[MAX], operator_stack_top = -1;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (is_space(expression[i]))
            continue;
        if (is_digit(expression[i]))
        {
            int x = 0;
            while (i < string_length(expression) && is_digit(expression[i]))
            {
                x = x * 10 + (expression[i++] - '0');
            }
            number_stack_top++;
            number_stack[number_stack_top] = x;
            i--;
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            while (operator_stack_top >= 0 && precedence(operator_stack[operator_stack_top]) >= precedence(expression[i]))
            {
                int y = number_stack[number_stack_top--];
                int x = number_stack[number_stack_top--];
                char op = operator_stack[operator_stack_top--];
                number_stack_top++;
                number_stack[number_stack_top] = operation(x, y, op);
            }
            operator_stack_top++;
            operator_stack[operator_stack_top] = expression[i];
        }
        else
        {
            printf("Error: Invalid expression.\n");
            exit(0);
        }
    }

    while (operator_stack_top >= 0)
    {
        int b = number_stack[number_stack_top--];
        int a = number_stack[number_stack_top--];
        char op = operator_stack[operator_stack_top--];
        number_stack[++number_stack_top] = operation(a, b, op);
    }

    return number_stack[number_stack_top];
}

int main()
{
    char expression[MAX];
    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);
    int ans = evaluate(expression);
    printf("Answer: %d\n", ans);
    return 0;
}