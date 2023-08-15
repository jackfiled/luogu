#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);

    vector<int> fruit;
    for (int i = 0; i < number; i++)
    {
        int temp;
        scanf("%d", &temp);
        fruit.push_back(temp);
    }

    make_heap(fruit.begin(), fruit.end(), greater<int>());
    int result = 0;
    while (fruit.size() != 1)
    {
        auto begin = fruit.begin(), end = fruit.end();

        pop_heap(begin, end, greater<int>());        
        int a = fruit.back();
        fruit.pop_back();
        end = fruit.end();

        pop_heap(begin, end, greater<int>());
        int b = fruit.back();
        fruit.pop_back();

        result = result + a + b;
        fruit.push_back(a + b);
        end = fruit.end();
        push_heap(begin, end, greater<int>());
    }

    printf("%d\n", result);
    return 0;
}