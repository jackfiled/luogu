#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int number;
    cin >> number;
    unordered_map<string, int> m;
    int result = 0;

    for (int i = 0; i < number; i++)
    {
        string a, b;
        cin >> a >> b;
        a = a.substr(0, 2);

        if (a != b)
        {
            result = result + m[a + b];
            m[b + a]++;
        }
    }

    cout << result << endl;
    return 0;
}