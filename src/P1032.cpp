#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct Rule
{
    string pattern, result;
};

struct State
{
    int depth;
    string now;
};

class BFS
{
public:
    int result = -1;

    void init()
    {
        cin >> begin >> end;

        string t1, t2;
        int pos = 0;
        while (cin >> t1 >> t2)
        {
            rules[pos].pattern = t1;
            rules[pos].result = t2;
            pos++;
        }
        count = pos;
    }

    void bfs()
    {
        State start;
        start.now = begin;
        start.depth = 0;

        q.push(start);

        while (!q.empty())
        {
            auto head = q.front();
            q.pop();

            if (used.count(head.now) == 1)
            {
                continue;
            }

            used[head.now] = 1;

            if (head.now == end)
            {
                result = head.depth;
                return;
            }

            for (int i = 0; i < count; i++)
            {
                size_t length = head.now.length();

                for (size_t j = 0; j < length; j++)
                {
                    if (j + rules[i].pattern.length() > length)
                    {
                        continue;
                    }

                    bool flag = true;
                    for (size_t k = 0; k < rules[i].pattern.length(); k++)
                    {
                        if (head.now[j + k] != rules[i].pattern[k])
                        {
                            flag = false;
                            break;
                        }
                    } 
                    if (!flag)
                    {
                        continue;
                    }

                    State next;
                    next.now = head.now.substr(0, j);
                    next.now += rules[i].result;
                    next.now += head.now.substr(j + rules[i].pattern.length());
                    next.depth = head.depth + 1;

                    if (next.depth <= 10)
                    {
                        q.push(next);
                    }
                }
            }
        }
    }

private:
    string begin, end;
    Rule rules[6];
    int count = 0;

    map<string, int> used;
    queue<State> q;
};

int main()
{
    BFS bfs;

    bfs.init();

    bfs.bfs();

    if (bfs.result == -1)
    {
        cout << "NO ANSWER!" << endl;
    }
    else
    {
        cout << bfs.result << endl;
    }

    return 0;
}