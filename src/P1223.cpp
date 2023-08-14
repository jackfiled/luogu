#include <cstdio>
#include <algorithm>

using namespace std;

struct Person
{
    int id;
    int time;
};

bool compare(const Person& a, const Person& b)
{
    return a.time < b.time;
}

int main()
{
    int number;
    scanf("%d", &number);

    Person people[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &people[i].time);
        people[i].id = i + 1;
    }

    sort(people, people + number, compare);

    double sum = 0, time = 0;
    for (int i = 0; i < number; i++)
    {
        if (i == number - 1)
        {
            printf("%d\n", people[i].id);
            break;
        }
        printf("%d ", people[i].id);
        time += people[i].time;
        sum += time;
    }

    printf("%.2lf\n", sum / number);
    return 0;
}