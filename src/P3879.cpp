#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int number;
    cin >> number;

    unordered_set<string> essays[number];

    for (int i = 0; i < number; i++)
    {
        int count;
        cin >> count;

        for (int j = 0; j < count; j++)
        {
            string word;
            cin >> word;

            essays[i].emplace(word);
        }
    }

    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string word;
        cin >> word;

        int result[number];
        int pos = 0;

        for (int j = 0; j < number; j++)
        {
            if (essays[j].count(word) == 1)
            {
                result[pos] = j + 1;
                pos++;
            }
        }

        for(int j = 0; j < pos; j++)
        {
            if (j == pos - 1)
            {
                printf("%d", result[j]);
            }
            else
            {
                printf("%d ", result[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
