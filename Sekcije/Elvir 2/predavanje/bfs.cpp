#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV		= 100000;

const int DFS_WHITE =	   0;
const int DFS_GREY  = 	   1;
const int DFS_BLACK = 	   2;

const int WHITE = 0;
const int BLACK = 1;

//<graf>
struct Edge
{
	int v, w;

	Edge() { } 
	Edge(int _v, int _w) { v = _v; w = _w; }
};

vector <Edge> graph [MAXV];

int color [MAXV];
//</graf>

int main()
{
	freopen ("unweighteddense.txt", "r", stdin);
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		graph [a].emplace_back(b, 0);
		graph [b].emplace_back(a, 0);
	}

	queue <int> q;
	for (int i = 1; i <= v; i++)
	{
		if (color [i] == WHITE)
		{
			q.push(i);

			while (!q.empty())
			{
				int u = q.top();
				q.pop();

				cout << "BFS: " << u << endl;

				color [u] = BLACK;

				for (edge e : graph [u])
					if (!color [e.v])
						q.push(e.v);
			}
		}
	}


	return 0;
}
























