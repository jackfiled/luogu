#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    string name;
    int direction;

    Person(string name, int direction);
};

Person::Person(string name, int direction)
{
    this->name = name;
    this->direction = direction;
}

int main()
{
    vector<Person> people;

    int personNumber, directionNumber;
    cin >> personNumber >> directionNumber;

    for (int i = 0; i < personNumber; i++)
    {
        int direction;
        string name;
        cin >> direction >> name;
        people.push_back(Person(name, direction));
    }

    int itor = 0;
    for (int i = 0; i < directionNumber; i++)
    {
        int direction, pos;
        cin >> direction >> pos;

        if (direction == people[itor].direction)
        {
            // 顺时针转动
            itor = ((itor - pos) % personNumber + personNumber) % personNumber;
        }
        else
        {
            // 逆时针转动
            itor = (itor + pos) % personNumber;
        }
    }

    cout << people[itor].name << endl;

    return 0;
}