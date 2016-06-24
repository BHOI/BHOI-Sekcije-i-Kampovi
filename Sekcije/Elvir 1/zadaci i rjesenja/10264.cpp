#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int weights   [1<<16];
    int potencies [1<<16];
    int n;

    while (scanf ("%d", &n) == 1)
    {
        memset (weights, 0, sizeof weights);
        memset (potencies, 0, sizeof potencies);

        for (int i = 0; i < (1<<n); i++)
            scanf ("%d", &weights [i]);

        int maximum = 0;

        //for each vertex
        for (int i = 0; i < (1<<n); i++)
        {
            int potency = 0;
            //for each neighbor
            for (int j = 0; j < n; j++)
            {
                potencies [i] += weights [i ^ (1<<j)];
            }
        }

        //for each vertex
        for (int i = 0; i < (1<<n); i++)
        {
            int potency = 0;
            //for each neighbor
            for (int j = 0; j < n; j++)
            {
                maximum = max (maximum, potencies [i] + potencies [i ^ (1<<j)]);
            }
        }

        printf ("%d\n", maximum);
    }


    return 0;
}
