#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack for operators
char opStack[MAX];
int opTop = -1;

// Stack for evaluation
int valStack[MAX];
int valTop = -1;

// Operator stack functions
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

// Value stack functions
void pushVal(int x)
{
    valStack[++valTop] = x;
}

int popVal()
{
    return valStack[valTop--];
}

// Operator precedence
int precedence(char x)
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

int main()
{
    char infix[MAX], postfix[MAX];
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
            while (opTop != -1 && precedence(peekOp()) >= precedence(ch))
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
        if (isdigit(ch))
        {
            pushVal(ch - '0');
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
                    pushVal((int)pow(b, a));
                    break;
            }
        }

        i++;
    }

    printf("Result = %d\n", popVal());

    return 0;
}        case '/':
        case '%': return 2;
        case '^': return 3;
    }
    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0, a, b, result;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Infix to Postfix Conversion
    while(infix[i] != '\0')
    {
        if(isdigit(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(')
        {
            pushOp(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(opStack[top1] != '(')
                postfix[j++] = popOp();
            popOp();
        }
        else
        {
            while(top1 != -1 && precedence(opStack[top1]) >= precedence(infix[i]))
                postfix[j++] = popOp();
            pushOp(infix[i]);
        }
        i++;
    }

    while(top1 != -1)
        postfix[j++] = popOp();

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    // Postfix Evaluation
    i = 0;
    while(postfix[i] != '\0')
    {
        if(isdigit(postfix[i]))
        {
            pushVal(postfix[i] - '0');
        }
        else
        {
            b = popVal();
            a = popVal();

            switch(postfix[i])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '%': result = a % b; break;
            }

            pushVal(result);
        }
        i++;
    }

    printf("Evaluated Result = %d\n", popVal());

    return 0;
}
