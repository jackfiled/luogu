#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0}
};

int main()
{
    ios::sync_with_stdio(false);

    int aLength;
    cin >> aLength;

    vector<int> a(aLength + 1);
    for (int i = 1; i <= aLength; i++)
    {
        char c;
        cin >> c;

        switch (c)
        {
            case 'A':
                a[i] = 0;
                break;
            case 'C':
                a[i] = 1;
                break;
            case 'G':
                a[i] = 2;
                break;
            case 'T':
                a[i] = 3;
                break;
        }
    }

    int bLength;
    cin >> bLength;

    vector<int> b(bLength + 1);
    for (int i = 1; i <= bLength; i++)
    {
        char c;
        cin >> c;

        switch (c)
        {
            case 'A':
                b[i] = 0;
                break;
            case 'C':
                b[i] = 1;
                break;
            case 'G':
                b[i] = 2;
                break;
            case 'T':
                b[i] = 3;
                break;
        }
    }

    vector<vector<int>> dp(aLength + 1, vector<int>(bLength + 1, 0));

    for (int i = 1; i <= aLength; i++)
    {
        dp[i][0] = dp[i - 1][0] + map[a[i]][4];
    }
    for (int i = 1; i <= bLength; i++)
    {
        dp[0][i] = dp[0][i - 1] + map[4][b[i]];
    }

    for (int i = 1; i <= aLength; i++)
    {
        for (int j = 1; j <= bLength; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1] + map[a[i]][b[j]], 
                max(dp[i - 1][j] + map[a[i]][4], dp[i][j - 1] + map[4][b[j]]));
        }
    }

    cout << dp[aLength][bLength] << endl;

    return 0;
}