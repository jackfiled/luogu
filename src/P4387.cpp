#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int q;
    scanf("%d", &q);

    for (int c = 0; c < q; c++)
    {
        int number;
        scanf("%d", &number);

        stack<int> array;

        int input[number];
        int output[number];

        for (int i = 0; i < number; i++)
        {
            scanf("%d", &input[i]);
        }
        for (int i = 0; i < number; i++)
        {
            scanf("%d", &output[i]);
        }

        int i = 0;
        for (int pos = 0; pos < number; pos++)
        {
            array.push(input[pos]);

            while(!array.empty() and array.top() == output[i])
            {
                array.pop();
                i++;
            }
        }
        

        if (i == number)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}