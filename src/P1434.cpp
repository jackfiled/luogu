#include <cstdio>
#include <queue>
#include <vector>

#define MAX(a, b) (a) > (b) ? (a) : (b)

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1}; 

struct Node
{
    int x, y, height;

    Node(int x, int y, int height) : x(x), y(y), height(height)
    {

    }
};

struct NodeComparer
{
    bool operator()(const Node& x, const Node& y)
    {
        return x.height > y.height;
    }
};

int main()
{
    int width, height;
    scanf("%d %d", &height, &width);
    vector<vector<int>> matrix(height + 2, vector<int>(width + 2, 0));
    vector<vector<int>> dp(height + 2, vector<int>(width + 2, 0));
    priority_queue<Node, vector<Node>, NodeComparer> queue;

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            int n;
            scanf("%d", &n);

            matrix[i][j] = n;
            dp[i][j] = 1;
            queue.push(Node(i, j, n));
        }
    }

    int result = 0;
    while (!queue.empty())
    {
        Node head = queue.top();
        queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = head.x + dx[i];
            int y = head.y + dy[i];

            if (matrix[x][y] < head.height)
            {
                dp[head.x][head.y] = MAX(dp[head.x][head.y], dp[x][y] + 1);
            }
        }

        result = MAX(result, dp[head.x][head.y]);
    }

    printf("%d\n", result);
    return 0;
}