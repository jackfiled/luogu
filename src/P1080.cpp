#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& a, int b)
{
    int overflow = 0;
    vector<int> result;
    for (auto i = a.begin(); i != a.end(); i++)
    {
        int temp = *i*b + overflow;
        result.push_back(temp % 10);
        overflow = temp / 10;
    }

    while(overflow != 0)
    {
        result.push_back(overflow % 10);
        overflow = overflow / 10;
    }

    return result;
}

vector<int> divide(const vector<int>& a, int b)
{
    int sum = 0;
    vector<int> result;
    bool flag = true;
    
    for (auto i = a.rbegin(); i != a.rend(); i++)
    {
        sum = sum * 10 + *i;
        int temp = sum / b;
        if (temp != 0)
        {
            flag = false;
        }

        if (flag and temp == 0)
        {
            continue;
        }
        result.push_back(temp);
        sum = sum - b * temp;
    }

    reverse(result.begin(), result.end());

    return result;
}

struct Minister
{
    int left;
    int right;
};

bool compare(const Minister& a, const Minister& b)
{
    return a.left * a.right < b.left * b.right;
}

int main()
{
    int number;
    scanf("%d", &number);
    Minister pm;
    scanf("%d %d", &pm.left, &pm.right);

    Minister ministers[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d %d", &ministers[i].left, &ministers[i].right);
    }

    sort(ministers, ministers + number, compare);

    vector<int> sum;
    int first = pm.left;
    while (first != 0)
    {
        sum.push_back(first % 10);
        first = first / 10;
    }

    for (int i = 0; i < number - 1; i++)
    {
        sum = multiply(sum, ministers[i].left);
    }

    sum = divide(sum, ministers[number - 1].right);

    for (auto i = sum.rbegin(); i != sum.rend(); i++)
    {
        printf("%d", *i);
    }
    if (sum.size() == 0)
    {
        if (number == 1)
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }
    else
    {
        printf("\n");
    }

    return 0;
}