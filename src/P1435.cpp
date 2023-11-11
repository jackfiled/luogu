#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string input;
    cin >> input;

    // 求倒序字符串
    string reverse;

    for (auto i = input.rbegin(); i != input.rend(); i++)
    {
        reverse += *i;
    }

    size_t length = input.length();
    vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));

    for (size_t i = 1; i <= length; i++)
    {
        for (size_t j = 1; j <= length; j++)
        {
            if (input[i - 1] == reverse[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << length - dp[length][length] << endl;
    return 0;
}