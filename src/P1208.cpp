#include <cstdio>
#include <algorithm>

using namespace std;

struct Milk
{
    int price, amount;
};

bool compare(const Milk& a, const Milk& b)
{
    if (a.price == b.price)
    {
        return a.amount > b.amount;
    }

    return a.price < b.price;
}

int main()
{
    int number, n;
    scanf("%d %d", &number, &n);

    Milk milks[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &milks[i].price, &milks[i].amount);
    }

    sort(milks, milks + n, compare);

    int now = 0, pos = 0;
    long long fee = 0;
    while (now < number)
    {
        if (milks[pos].amount < number - now)
        {
            now += milks[pos].amount;
            fee += milks[pos].amount * milks[pos].price;
        }
        else
        {
            fee += (number - now) * milks[pos].price;
            now = number;
        }

        pos++;
    }

    printf("%lld\n", fee);
    return 0;
}