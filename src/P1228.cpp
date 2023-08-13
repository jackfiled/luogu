#include <cstdio>
#include <cmath>

void solve(int x, int y, int a, int b, int length)
{
    if (length == 1)
    {
        return;
    }

    // 判断公主所在的位置
    if (x - a <= length / 2 - 1 and y - b <= length / 2 - 1)
    {
        // 公主在左上角
        printf("%d %d 1\n", a + length / 2, b + length / 2);
        solve(x, y, a, b, length / 2);

        // 剩下的三块，毯子就是公主
        solve(a + length / 2 - 1, b + length / 2, a, b + length / 2, length / 2);
        solve(a + length / 2, b + length / 2 - 1, a + length / 2, b, length / 2);
        solve(a + length / 2, b + length / 2, a + length / 2, b + length / 2, length / 2);
    }
    else if (x - a > length / 2 - 1 and y - b <= length / 2 - 1)
    {
        // 公主在左下角
        printf("%d %d 3\n", a + length / 2 - 1, b + length / 2);

        solve(a + length / 2 - 1, b + length / 2 - 1, a, b, length / 2);
        solve(a + length / 2 - 1, b + length / 2, a, b + length / 2, length / 2);
        solve(x, y, a + length / 2, b, length / 2);
        solve(a + length / 2, b + length / 2, a + length / 2, b + length / 2, length / 2);
    }
    else if (x - a <= length / 2 - 1 and y - b > length / 2 - 1)
    {
        // 公主在右上角
        printf("%d %d 2\n", a + length / 2, b + length / 2 - 1);

        solve(a + length / 2 - 1, b + length / 2 - 1, a, b, length / 2);
        solve(x, y, a, b + length / 2, length / 2);
        solve(a + length / 2, b + length / 2 - 1, a + length / 2, b, length / 2);
        solve(a + length / 2, b + length / 2, a + length / 2, b + length / 2, length / 2);
    }
    else
    {
        // 公主在右下角
        printf("%d %d 4\n", a + length / 2 - 1, b + length / 2 - 1);

        solve(a + length / 2 - 1, b + length / 2 - 1, a, b, length / 2);
        solve(a + length / 2 - 1, b + length / 2, a, b + length / 2, length / 2);
        solve(a + length / 2, b + length / 2 - 1, a + length / 2, b, length / 2);
        solve(x, y, a + length / 2, b + length / 2, length / 2);
    }
}

int main()
{
    int x, y, k;
    scanf("%d %d %d", &k, &x, &y);

    solve(x, y, 1, 1, pow(2, k));
    return 0;
}