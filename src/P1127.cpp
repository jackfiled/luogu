#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct UnionFind
{
    unordered_map<int, int> father;

    int find(int x)
    {
        if (father[x] == x)
        {
            return x;
        }

        father[x] = find(father[x]);
        return father[x];
    }

    void merge(int x, int y)
    {
        father[y] = x;
    }
};

struct Edge
{
    int order;
    int out;
    string word;

    Edge(int order, int out, string word) : order(order), out(out), word(word) {}
};

struct Graph
{
    vector<vector<Edge>> Edges;
    int in[26];
    int out[26];
    vector<bool> visit;
    vector<string> answer;
    size_t size;

    Graph(int number)
    {
        Edges = vector<vector<Edge>>(26);

        for (int i = 0; i < 26; i++)
        {
            in[i] = 0;
            out[i] = 0;
        }

        visit = vector<bool>(number + 1, false);
        answer = vector<string>(number + 1);
        size = number;
    }

    void dfs(size_t pos, int now, int pre_edge)
    {
        if (pos == size)
        {
            for (size_t i = 0; i < size; i++)
            {
                cout << answer[i];

                if (i != size - 1)
                {
                    cout << '.';
                }
            }
            cout << endl;
            exit(0);
        }

        for (const auto &edge : Edges[now])
        {
            if (!visit[edge.order])
            {
                visit[edge.order] = true;
                
                answer[pos] = edge.word;
                dfs(pos + 1, edge.out, edge.order);
            }
        }

        visit[pre_edge] = false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int number;
    cin >> number;

    string input[number];

    for (int i = 0; i < number; i++)
    {
        cin >> input[i];
    }

    sort(input, input + number);

    // 判断一个字母是否出现过
    // 利用并查集判断能否首尾相连
    // 顺便建图
    bool letter[26] = {false};
    int set_count = 0;
    UnionFind unionFind;
    Graph graph(number);

    for (int i = 0; i < number; i++)
    {
        int start = input[i][0] - 'a';
        int end = input[i][input[i].size() - 1] - 'a';

        if (!letter[start])
        {
            set_count++;
            letter[start] = true;
            unionFind.father[start] = start;
        }

        if (!letter[end])
        {
            set_count++;
            letter[end] = true;
            unionFind.father[end] = end;
        }

        if (start != end)
        {
            if (unionFind.find(start) != unionFind.find(end))
            {
                set_count--;
                unionFind.merge(unionFind.find(start),
                                unionFind.find(end));
            }
        }

        // 建图
        Edge edge(i, end, input[i]);

        graph.Edges[start].push_back(edge);
        graph.in[end]++;
        graph.out[start]++;
    }

    if (set_count != 1)
    {
        cout << "***" << endl;
        return 0;
    }

    int eularStart = -1, eularEnd = -1;

    for (int i = 0; i < 26; i++)
    {
        if (!letter[i])
        {
            continue;
        }

        if (graph.out[i] == graph.in[i] + 1)
        {
            // 出度比入度大一，事起点
            if (eularStart != -1)
            {
                cout << "***" << endl;
                return 0;
            }
            eularStart = i;
        }
        else if (graph.in[i] == graph.out[i] + 1)
        {
            if (eularEnd != -1)
            {
                cout << "***" << endl;
                return 0;
            }
            eularEnd = i;
        }
        else if (graph.in[i] == graph.out[i])
        {
            continue;
        }
        else
        {
            cout << "***" << endl;
            return 0;
        }
    }

    // 有始无终/有终无始都是错的
    if ((eularStart == -1 and eularEnd != -1) or
        (eularStart != -1 and eularEnd == -1))
    {
        cout << "***";
        return 0;
    }

    // 如果无始无终，说明是有环图
    if (eularStart == -1)
    {
        eularStart = input[0][0] - 'a';
    }

    graph.dfs(0, eularStart, 0);

    return 0;
}