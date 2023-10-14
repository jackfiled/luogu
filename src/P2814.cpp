#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct UnionFind
{
    unordered_map<string, string> fathers;

    string find(string x)
    {
        if (fathers.count(x) == 0 || fathers.at(x) == x)
        {
            return x;
        }

        fathers[x] = find(fathers[x]);
        return fathers.at(x);
    }

    void merge(string a, string b)
    {
        fathers[find(a)] = find(b);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    string father;
    UnionFind unionFind;

    while (true)
    {
        char control;
        cin >> control;

        if (control == '$')
        {
            break;
        }
        else if (control == '#')
        {
            cin >> father;
            continue;
        }

        string input;
        cin >> input;

        if (control == '+')
        {
            unionFind.merge(input, father);
        }
        else if (control == '?')
        {
            printf("%s %s\n", input.c_str(), unionFind.find(input).c_str());
        }
    }

    return 0;
}