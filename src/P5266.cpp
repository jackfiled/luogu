#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int number;
    cin >> number;

    unordered_map<string, int> students;
    for (int i = 0; i < number; i++)
    {
        int control;
        cin >> control;

        switch (control)
        {
        case 1:
        {
            string name;
            int score;
            cin >> name >> score;

            students[name] = score;
            printf("OK\n");
            break;
        }
        case 2:
        {
            string name;
            cin >> name;

            if (students.count(name) != 0)
            {
                printf("%d\n", students.at(name));
            }
            else
            {
                printf("Not found\n");
            }
            break;
        }
        case 3:
        {
            string name;
            cin >> name;

            if (students.count(name) != 0)
            {
                students.erase(name);
                printf("Deleted successfully\n");
            }
            else
            {
                printf("Not found\n");
            }
            break;
        }
        case 4:
        {
            printf("%ld\n", students.size());
            break;
        }
        }
    }

    return 0;
}