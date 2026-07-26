#include <stdio.h>
#include <ctype.h>

#define N 100

char opStack[N];
int opTop = -1;

int valStack[N];
int valTop = -1;

void pushOp(char x)
{
    opStack[++opTop] = x;
}

char popOp()
{
    return opStack[opTop--];
}

char peekOp()
{
    return opStack[opTop];
}

void pushVal(int x)
{
    valStack[++valTop] = x;
}

int popVal()
{
    return valStack[valTop--];
}

int prece(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    if (x == '^')
        return 3;
    return -1;
}

// Function to calculate power
int power(int base, int exp)
{
    int result = 1;

    while (exp > 0)
    {
        result *= base;
        exp--;
    }

    return result;
}

int main()
{
    char infix[N], postfix[N];
    int i = 0, j = 0;
    char ch;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    // Infix to Postfix Conversion
    while ((ch = infix[i]) != '\0')
    {
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            pushOp(ch);
        }
        else if (ch == ')')
        {
            while (peekOp() != '(')
                postfix[j++] = popOp();

            popOp();
        }
        else
        {
            while (opTop != -1 && prece(peekOp()) >= prece(ch))
                postfix[j++] = popOp();

            pushOp(ch);
        }

        i++;
    }

    while (opTop != -1)
        postfix[j++] = popOp();

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    // Postfix Evaluation
    i = 0;

    while ((ch = postfix[i]) != '\0')
    {
        if (isalnum(ch))
        {
            if (isdigit(ch))
            {
                pushVal(ch - '0');
            }
            else
            {
                int value;
                printf("Enter value of %c: ", ch);
                scanf("%d", &value);
                pushVal(value);
            }
        }
        else
        {
            int a = popVal();
            int b = popVal();

            switch (ch)
            {
                case '+':
                    pushVal(b + a);
                    break;

                case '-':
                    pushVal(b - a);
                    break;

                case '*':
                    pushVal(b * a);
                    break;

                case '/':
                    pushVal(b / a);
                    break;

                case '%':
                    pushVal(b % a);
                    break;

                case '^':
                    pushVal(power(b, a));
                    break;
            }
        }

        i++;
    }

    printf("Result = %d\n", popVal());

    return 0;
}
