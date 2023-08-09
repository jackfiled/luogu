#include <iostream>
#include <string>

using namespace std;

string read()
{
    char c;
    string result;
    
    while(cin >> c)
    {
        if (c == '[')
        {
            int number;
            cin >> number;
            string inner = read();

            for (int i = 0; i < number; i++)
            {
                result = result + inner;
            }
        }
        else if (c == ']')
        {
            return result;
        }
        else
        {
            result = result + c;
        }
    }

    return result;
}

int main()
{
    string result = read();
    cout << result << endl;
}