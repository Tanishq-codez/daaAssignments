#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
};

double distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

pair<double, pair<Point, Point>> findClosestPair(vector<Point> &points, int start, int end)
{
    if (end - start <= 1)
    {
        return {1e18, {{0, 0}, {0, 0}}};
    }

    if (end - start == 2)
    {
        double d = distance(points[start], points[start + 1]);
        return {d, {points[start], points[start + 1]}};
    }

    int mid = (start + end) / 2;
    double midX = (points[mid - 1].x + points[mid].x) / 2;

    auto left = findClosestPair(points, start, mid);
    auto right = findClosestPair(points, mid, end);

    double minDist = min(left.first, right.first);
    pair<double, pair<Point, Point>> result = left.first < right.first ? left : right;

    // Check for points crossing the midline
    vector<Point> strip;
    for (int i = start; i < end; i++)
    {
        if (abs(points[i].x - midX) < minDist)
        {
            strip.push_back(points[i]);
        }
    }

    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < min((int)strip.size(), i + 7); j++)
        {
            double d = distance(strip[i], strip[j]);
            if (d < minDist)
            {
                minDist = d;
                result = {d, {strip[i], strip[j]}};
            }
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Point> points = {
        {9, 3}, {2, 6}, {15, 3}, {5, 1}, {1, 2}, {12, 4}, {7, 2}, {4, 7}, {16, 5}, {3, 3}, {10, 5}, {6, 4}, {14, 6}, {8, 6}, {11, 1}, {13, 2}};

    // Sort by x-coordinate
    sort(points.begin(), points.end(), [](Point a, Point b)
         { return a.x < b.x; });

    auto result = findClosestPair(points, 0, points.size());

    cout << "Minimum Euclidean distance = " << fixed << setprecision(2) << result.first << endl;
    cout << "Between points (" << result.second.first.x << "," << result.second.first.y << ") and ("
         << result.second.second.x << "," << result.second.second.y << ")" << endl;

    return 0;
}
