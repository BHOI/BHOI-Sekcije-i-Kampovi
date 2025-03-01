#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	int n = 1;

	while (scanf ("%d", &n) == 1 && n != 0)
	{
		int x, cost = 0, a;
		priority_queue <int, vector <int>, greater <int> > q;
		
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			q.push(x);
		}

		while (q.size() > 1)
		{
			a = q.top();
			q.pop();
			a += q.top();
			q.pop();

			cost += a;
			q.push(a);
		}

		cout << cost << endl;
	}

	return 0;
}
