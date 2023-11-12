#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    double x, y;
};

bool compare(const Point &a, const Point &b)
{
    if (a.x == b.x)
    {
        return a.y < b.y;
    }

    return a.x < b.x;
}

double dis(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct Merge
{
    vector<Point> points;

    Merge(int number)
    {
        points = vector<Point>(number);
    }

    double merge(int left, int right)
    {
        if (left == right)
        {
            return 2 << 20;
        }

        if (left + 1 == right)
        {
            return dis(points[left], points[right]);
        }

        int mid = (left + right) / 2;
        double leftDistance = merge(left, mid);
        double rightDistance = merge(mid + 1, right);

        double distance = min(leftDistance, rightDistance);

        // 考虑最近点对分别在两边的情况
        // 只考虑在[mid - distance, mid + distance]范围之内的点
        vector<int> array;

        for (int i = left; i <= right; i++)
        {
            if (fabs(points[i].x - points[mid].x) < distance)
            {
                array.push_back(i);
            }
        }

        for (size_t i = 0; i < array.size(); i++)
        {
            for (size_t j = i + 1; j < array.size(); j++)
            {
                distance = min(distance, dis(points[array[i]], points[array[j]]));
            }
        }

        return distance;
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    Merge m(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &m.points[i].x, &m.points[i].y);
    }

    sort(m.points.begin(), m.points.end(), compare);

    printf("%.2lf\n", m.merge(0, n - 1));

    return 0;
}