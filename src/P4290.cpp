#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline int function(char c)
{
    switch (c)
    {
    case 'W':
        return 0;
    case 'I':
        return 1;
    case 'N':
        return 2;
    case 'G':
        return 3;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    int W, I, N, G;
    cin >> W >> I >> N >> G;
    // map[i][j][k] 表示i 可以转移到jk
    vector<vector<vector<bool>>> map(4, vector<vector<bool>>(4, vector<bool>(4, false)));

    for (int i = 0; i < W; ++i)
    {
        string temp;
        cin >> temp;
        map[0][function(temp[0])][function(temp[1])] = true;
    }

    for (int i = 0; i < I; ++i)
    {
        string temp;
        cin >> temp;
        map[1][function(temp[0])][function(temp[1])] = true;
    }

    for (int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        map[2][function(temp[0])][function(temp[1])] = true;
    }

    for (int i = 0; i < G; ++i)
    {
        string temp;
        cin >> temp;
        map[3][function(temp[0])][function(temp[1])] = true;
    }

    string target;
    cin >> target;

    int length = target.length();

    vector<vector<vector<bool>>> dp(length + 1, vector<vector<bool>>(length + 1, vector<bool>(4, false)));

    for (int i = 0; i < length; ++i)
    {
        dp[i][i][function(target[i])] = true;
    }

    for (int len = 1; len < length; ++len)
    {
        for (int left = 0, right = left + len; right < length; ++left, ++right)
        {
            for (int mid = left; mid < right; ++mid)
            {
                // 枚举[left, right]
                for (int i = 0; i < 4; ++i)
                {
                    // 枚举[left, mid]
                    for (int j = 0; j < 4; ++j)
                    {
                        // 枚举[mid + 1, right]
                        for (int k = 0; k < 4; ++k)
                        {
                            if (map[i][j][k] and dp[left][mid][j] and dp[mid + 1][right][k])
                            {
                                dp[left][right][i] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    bool f = false;
    if (dp[0][length - 1][0])
    {
        f = true;
        cout << "W";
    }
    if (dp[0][length - 1][1])
    {
        f = true;
        cout << "I";
    }
    if (dp[0][length - 1][2])
    {
        f = true;
        cout << "N";
    }
    if (dp[0][length - 1][3])
    {
        f = true;
        cout << "G";
    }

    if (!f)
    {
        cout << "The name is wrong!";
    }

    cout << endl;
    return 0;
}