#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class BFS {
public:
    int number;
    int target;

    void dfs(int now, int next)
    {
        if (now == target)
        {
            for (auto i : queue)
            {
                cout << setw(3) << i;
            }
            cout << endl;
            return;
        }

        for (int i = next; i <= number; i++)
        {
            
            queue.push_back(i);
            dfs(now + 1, i + 1);
            queue.pop_back();
        }
    }

private:
    vector<int> queue;
};

int main()
{
    BFS dfs;
    scanf("%d %d", &dfs.number, &dfs.target);

    dfs.dfs(0, 1);
    return 0;
}