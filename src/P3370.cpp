#include <set>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int number;
    cin >> number;
    set<string> s;

    for (int i = 0; i < number; i++)
    {
        string input;
        cin >> input;

        s.emplace(input);
    }

    cout << s.size() << endl;
    return 0;
}