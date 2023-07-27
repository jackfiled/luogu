#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    int chinese;
    int math;
    int english;
    int sum;
};

bool compare(const Student& a, const Student& b)
{
    if (a.sum == b.sum)
    {
        if (a.chinese == b.chinese)
        {
            return a.id < b.id;
        }

        return a.chinese > b.chinese;
    }

    return a.sum > b.sum;
}

int main()
{
    int number;
    scanf("%d", &number);

    Student students[number];

    for (int i = 1; i <= number; i++)
    {
        scanf("%d %d %d", &students[i - 1].chinese, 
            &students[i - 1].math, &students[i - 1].english);

        students[i - 1].sum = students[i - 1].chinese
            + students[i - 1].math + students[i - 1].english;
        
        students[i - 1].id = i;
    }

    sort(students, students + number, compare);

    for (int i = 0; i < 5; i++)
    {
        printf("%d %d\n", students[i].id, students[i].sum);
    }
    return 0;
}