#include <cstdio>
#include <vector>

using namespace std;

struct Parentness
{
    char c;
    bool paired;
};

int main()
{
    vector<Parentness> sentence;

    while (true)
    {
        char input = getchar();

        if (input == '\r')
        {
            break;
        }

        if (input == '(' or input == '[')
        {
            Parentness p = {
                .c = input,
                .paired = false,
            };

            sentence.push_back(p);
        }
        else
        {
            bool flag = false;
            for (auto i = sentence.rbegin(); i != sentence.rend(); i++)
            {
                if ((!i->paired) and (i->c == '(' or i->c == '['))
                {
                    if ((i->c == '(' and input == ')') or (i->c == '[' and input == ']'))
                    {
                        Parentness p = {
                            .c = input,
                            .paired = true
                        };
                        i->paired = true;

                        sentence.push_back(p);
                        flag = true;
                    }

                    break;
                }
            }

            if (!flag)
            {
                Parentness p = {
                    .c = input,
                    .paired = false
                };

                sentence.push_back(p);
            }
        }
    }

    for (auto i : sentence)
    {
        if (i.paired)
        {
            printf("%c", i.c);
        }
        else
        {
            if (i.c == '(' or i.c == ')')
            {
                printf("()");
            }
            else
            {
                printf("[]");
            }
        }
    }

    return 0;
}