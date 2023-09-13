#include <cstdio>
#include <stack>

using namespace std;

int pop(stack<int> &stack)
{
    int result = stack.top();
    stack.pop();

    return result;
}

int main()
{
    stack<int> expression;
    int number = 0;

    while (true)
    {
        char input = getchar();

        if (input == '@')
        {
            break;
        }

        switch (input)
        {
        case '+':
        {
            int b = pop(expression);
            int a = pop(expression);

            expression.push(a + b);
            break;
        }
        case '-':
        {
            int b = pop(expression);
            int a = pop(expression);

            expression.push(a - b);
            break;
        }
        case '*':
        {
            int b = pop(expression);
            int a = pop(expression);

            expression.push(a * b);
            break;
        }
        case '/':
        {
            int b = pop(expression);
            int a = pop(expression);

            expression.push(a / b);
            break;
        }
        case '.':
        {
            expression.push(number);
            number = 0;
            break;
        }
        default:
            number = number * 10 + input - 48;
            break;
        }
    }

    printf("%d\n", expression.top());

    return 0;
}