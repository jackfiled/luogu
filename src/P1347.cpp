#include <cstdio>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

// 拓扑遍历中的节点
// 方便计算深度
struct Node
{
    int p, depth;

    Node(int p, int depth) : p(p), depth(depth) {}
};

struct Graph
{
    int size;
    vector<vector<int>> points;
    vector<int> in;

    Graph(int number)
    {
        size = number;
        points = vector<vector<int>>(number);

        in = vector<int>(number, 0);
    }

    bool topo(int m)
    {
        vector<int> result;
        queue<Node> q;
        vector<int> inTemp(in);

        // 计算是否能够遍历完全
        int count = 0;
        // 计算遍历的深度
        int depth = 1;
        
        for (int i = 0; i < size; i++)
        {
            if (in[i] == 0)
            {
                q.push(Node(i, 1));
                result.push_back(i);
                count++;
            }
        }

        while (!q.empty())
        {
            auto& head = q.front();
            q.pop();

            for (int& i : points[head.p])
            {
                inTemp[i]--;

                if (inTemp[i] == 0)
                {
                    count++;
                    q.push(Node(i, head.depth + 1));
                    result.push_back(i);

                    depth = max(depth, head.depth + 1);
                }
            }
        }

        if (depth == size)
        {
            printf("Sorted sequence determined after %d relations: ", m);
            for (int& i : result)
            {
                printf("%c", 'A' + i);
            }
            printf(".\n");
            return true;
        }

        if (count != size)
        {
            printf("Inconsistency found after %d relations.\n", m);
            return true;
        }

        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    Graph graph(n);

    bool flag;
    for (int i = 0; i < m; i++)
    {
        string input;
        cin >> input;
        

        graph.points[input[0] - 'A'].push_back(input[2] - 'A');
        graph.in[input[2] - 'A']++;

        if (graph.topo(i + 1))
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}