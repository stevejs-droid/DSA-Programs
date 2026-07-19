#include <stdio.h>
#include <ctype.h>

#define MAX 100

char opStack[MAX];
int valStack[MAX];
int top1 = -1, top2 = -1;

void pushOp(char ch)
{
    opStack[++top1] = ch;
}

char popOp()
{
    return opStack[top1--];
}

void pushVal(int x)
{
    valStack[++top2] = x;
}

int popVal()
{
    return valStack[top2--];
}

int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
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
