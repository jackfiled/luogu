#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    int year;
    int month;
    int day;
    int id;
    char name[21];
};

bool compare(const Student& a, const Student& b)
{
    if (a.year == b.year)
    {
        if (a.month == b.month)
        {
            if (a.day == b.day)
            {
                return a.id > b.id;
            }

            return a.day < b.day;
        }

        return a.month < b.month;
    }

    return a.year < b.year;
}

int main()
{
    int number;
    scanf("%d", &number);

    Student students[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%s %d %d %d", students[i].name, &students[i].year, &students[i].month, &students[i].day);
        students[i].id = i;
    }

    sort(students, students + number, compare);

    for (int i = 0; i < number; i++)
    {
        printf("%s\n", students[i].name);
    }
    return 0;
}

