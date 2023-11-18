#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Item
{
    double time, value;
};

bool compare(const Item &a, const Item &b)
{
    return a.value / a.time > b.value / b.time;
}

struct Backward
{
    vector<Item> items;
    int number, time;
    int result = 0;

    Backward()
    {
        scanf("%d %d", &time, &number);

        items.resize(number + 1);

        for (int i = 1; i <= number; i++)
        {
            scanf("%lf %lf", &items[i].time, &items[i].value);
        }

        sort(items.begin() + 1, items.end(), compare);
    }

    double evalue(int i, double current_time)
    {
        double upperbound = 0, left = time - current_time;
        for (int j = i; j <= number; j++)
        {
            if (left >= items[i].time)
            {
                upperbound += items[j].value;
                left -= items[j].time;
            }
            else
            {
                upperbound += items[j].value / items[j].time * left;
                return upperbound;
            }
        }
        return upperbound;
    }

    void backtrace(int i, double current_value, double current_time)
    {
        if (i > number)
        {
            result = max(result, (int)current_value);
            return;
        }

        if (current_time + items[i].time <= time)
        {
            backtrace(i + 1, current_value + items[i].value, current_time + items[i].time);
        }
        if (current_value + evalue(i + 1, current_time) > result)
        {
            backtrace(i + 1, current_value, current_time);
        }
    }
};

int main()
{
    Backward back;

    back.backtrace(1, 0, 0);
    printf("%d\n", back.result);
    return 0;
}