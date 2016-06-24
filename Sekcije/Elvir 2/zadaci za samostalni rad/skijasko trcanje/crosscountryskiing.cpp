#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <climits>

using namespace std;

const int dirX [4] = { -1, 0, 1, 0 };
const int dirY [4] = { 0, 1, 0, -1 };

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y) { x = _x; y = _y; }
};

point waypoint;

int n, m, waypoint_count;
bool waypoints [510] [510];
int elevation [510] [510];
bool visited [510] [510];
queue <point> Q;

bool check(int D)
{
    int counter = 0;
    memset (visited, false, sizeof visited);

    Q.push(waypoint);

    while (!Q.empty())
    {
        point help = Q.front();
        Q.pop();
        if (!visited [help.x] [help.y])
        {
            counter += waypoints [help.x] [help.y];
            visited [help.x] [help.y] = true;

            for (int i = 0; i < 4; i++)
            {
                int X = help.x + dirX [i];
                int Y = help.y + dirY [i];

                if (!visited [X] [Y] && abs (elevation [X] [Y] - elevation [help.x] [help.y]) <= D)
                    Q.push(point(X, Y));
            }
        }
    }

    return counter == waypoint_count;
}

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            elevation [i] [j] = INT_MAX;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf ("%d", &elevation [i] [j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf ("%d", &waypoints [i] [j]);
            if (waypoints [i] [j])
            {
                waypoint = point(i, j);
                waypoint_count++;
            }
        }
    }

    int left = -1, right = 1e9 + 1, pivot, solution = INT_MAX;

    while (left <= right)
    {
        pivot = (left + right + 1) / 2;

        if (check (pivot))
        {
            solution = min (solution, pivot);
            right = pivot - 1;
        }
        else
            left = pivot;

        if (left == right)
            break;
    }

    printf ("%d\n", solution);

    return 0;
}
























