#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> array;

    int n;
    while (scanf("%d", &n) != EOF)
    {
        array.push_back(n);
    }

    vector<int> dp;
    dp.push_back(array[0]);

    for (size_t i = 1; i < array.size(); i++)
    {
        if (*dp.rbegin() >= array[i])
        {
            dp.push_back(array[i]);
        }
        else
        {
            *upper_bound(dp.begin(), dp.end(), array[i], greater<int>()) = array[i];   
        }
    }

    printf("%ld\n", dp.size());

    dp.clear();
    dp.push_back(array[0]);

    for (size_t i = 1; i < array.size(); i++)
    {
        if (*dp.rbegin() < array[i])
        {
            dp.push_back(array[i]);
        }
        else
        {
            *lower_bound(dp.begin(), dp.end(), array[i]) = array[i];
        }
    }

    printf("%ld\n", dp.size());
    return 0;
}