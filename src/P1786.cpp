#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Person {
    char name[31];
    char position[10];
    long contribution;
    int grade;
    int id; 
};

int compare1(const Person& a, const Person& b)
{
    if (a.contribution == b.contribution)
    {
        return a.id < b.id;
    }

    return a.contribution > b.contribution;
}

int position2num(const char *position)
{
    if (strcmp(position, "BangZhu") == 0)
    {
        return 0;
    }
    if (strcmp(position, "FuBangZhu") == 0)
    {
        return 1;
    }
    if (strcmp(position, "HuFa") == 0)
    {
        return 2;
    }
    if (strcmp(position, "ZhangLao") == 0)
    {
        return 3;
    }
    if (strcmp(position, "TangZhu") == 0)
    {
        return 4;
    }
    if (strcmp(position, "JingYing") == 0)
    {
        return 5;
    }
    if (strcmp(position, "BangZhong") == 0)
    {
        return 6;
    }
    return 7;
}

int compare2(const Person& a, const Person& b)
{
    int aPosition = position2num(a.position);
    int bPosition = position2num(b.position);

    if (aPosition == bPosition)
    {
        if (a.grade == b.grade)
        {
            return a.id < b.id;
        }
        
        return a.grade > b.grade;
    }

    return aPosition < bPosition;
}

int main()
{
    int number;
    scanf("%d", &number);

    Person people[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%s %s %ld %d", people[i].name, people[i].position,
            &people[i].contribution, &people[i].grade);
        people[i].id = i;

        // 将帮主和副帮主的帮贡设的较大
        if (strcmp(people[i].position, "BangZhu") == 0)
        {
            people[i].contribution = 2000000000;
        }
        
        if (strcmp(people[i].position, "FuBangZhu") == 0)
        {
            people[i].contribution = 2000000000 - 5;
        }
    }

    sort(people, people + number, compare1);

    for (int i = 0; i < number; i++)
    {
        if (i == 0)
        {
            strcpy(people[i].position, "BangZhu");
        }
        else if (i >= 1 and i <= 2)
        {
            strcpy(people[i].position, "FuBangZhu");
        }
        else if (i >= 3 and i <= 4)
        {
            strcpy(people[i].position, "HuFa");
        }
        else if (i >= 5 and i <= 8)
        {
            strcpy(people[i].position, "ZhangLao");
        }
        else if (i >= 9 and i <= 15)
        {
            strcpy(people[i].position, "TangZhu");
        }
        else if (i >= 16 and i <= 40)
        {
            strcpy(people[i].position, "JingYing");
        }
        else
        {
            strcpy(people[i].position, "BangZhong");
        }
    }

    sort(people, people + number, compare2);

    for (int i = 0; i < number; i++)
    {
        printf("%s %s %d\n", people[i].name, people[i].position, people[i].grade);
    }

    return 0;
}