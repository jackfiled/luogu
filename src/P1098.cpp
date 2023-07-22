#include <cstdio>

int main()
{
    int p1, p2, p3;
    char input[101];

    scanf("%d %d %d", &p1, &p2, &p3);
    getchar();
    scanf("%s", input);

    char before = 127, middle = 127, after = 127;
    for (char *c = input; *c != '\0'; c++)
    {
        before = middle;
        middle = after;
        after = *c;
        if (before != 127)
        {
            printf("%c", before);
        }

        if (middle == '-')
        {
            if (before < after)
            {
                if (before >= '0' and before <= '9' and after >= '0' and after <= '9')
                {
                    middle = 127;
                    // 均为数字
                    if (p3 == 1)
                    {
                        // 正序
                        for (char c = before + 1; c <= after - 1; c++)
                        {
                            if (p1 == 3)
                            {
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("*");
                                }
                            }
                            else
                            {
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("%c", c);
                                }
                            }
                        }
                    }
                    else
                    {
                        // 倒序
                        for (char c = after - 1; c >= before + 1; c--)
                        {
                            if (p1 == 3)
                            {
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("*");
                                }
                            }
                            else
                            {
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("%c", c);
                                }
                            }
                        }
                    }
                }
                else if (before >= 'a' and before <= 'z' and after >= 'a' and after <= 'z')
                {
                    middle = 127;
                    // 均为小写字母
                    if (p3 == 1)
                    {
                        // 正序
                        for (char c = before + 1; c <= after - 1; c++)
                        {
                            if (p1 == 3)
                            {
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("*");
                                }
                            }
                            else if (p1 == 2)
                            {
                                // 打印大写字母
                                char bigC = c + 'A' - 'a';
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("%c", bigC);
                                }
                            }
                            else
                            {
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("%c", c);
                                }
                            }
                        }
                    }
                    else
                    {
                        // 倒序
                        for (char c = after - 1; c >= before + 1; c--)
                        {
                            if (p1 == 3)
                            {
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("*");
                                }
                            }
                            else if (p1 == 2)
                            {
                                // 打印大写字母
                                char bigC = c + 'A' - 'a';
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("%c", bigC);
                                }
                            }
                            else
                            {
                                for (int i = 0; i < p2; i++)
                                {
                                    printf("%c", c);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (middle != 127)
    {
        printf("%c", middle);
    }
    printf("%c\n", after);
    return 0;
}