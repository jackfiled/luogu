#include <cstdio>
#include <memory>
#include <vector>
#include <queue>

using namespace std;

const int mod = 80112002;

struct Graph
{
    int size;
    unique_ptr<vector<int>[]> points;
    unique_ptr<int[]> in;
    unique_ptr<int[]> out;

    Graph(int number)
    {
        size = number;
        points = unique_ptr<vector<int>[]>(new vector<int>[number + 1]);
        in = unique_ptr<int[]>(new int[number + 1]);
        out = unique_ptr<int[]>(new int[number + 1]);

        for (int i = 1; i <= number; i++)
        {
            in[i] = 0;
            out[i] = 0;
        }
    }

    unique_ptr<int[]> totp()
    {
        queue<int> q;
        unique_ptr<int[]> numbers = unique_ptr<int[]>(new int[size + 1]);

        for (int i = 1; i <= size; i++)
        {
            if (in[i] == 0)
            {
                numbers[i] = 1;
                q.push(i);
            }   
            else
            {
                numbers[i] = 0;
            }
        }

        while (!q.empty())
        {
            int head = q.front();
            q.pop();

            for (int& i : points[head])
            {
                in[i]--;

                numbers[i] = (numbers[i] + numbers[head]) % mod;

                if (in[i] == 0)
                {
                        q.push(i);
                }
            }
        }

        return numbers;
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Graph graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        graph.points[a].push_back(b);

        graph.in[b]++;
        graph.out[a]++;
    }

    unique_ptr<int[]> numbers = graph.totp();

    long long result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (graph.out[i] == 0)
        {
            result = (result + numbers[i]) % mod;
        }
    }

    printf("%lld\n", result);
    return 0;
}

