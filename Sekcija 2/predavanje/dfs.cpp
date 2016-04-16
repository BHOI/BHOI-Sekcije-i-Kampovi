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

void dfs(int u)
{
	cout << "entering node " << u << endl;
	color [u] = DFS_GREY;

	for (auto next : graph [u])
		if (color [next.v] == DFS_WHITE)
			dfs (next.v);

	color [u] = DFS_BLACK;
	cout << "exiting node " << u << endl;
}

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
	
	for (int i = 1; i <= v; i++)
		if (color [i] == DFS_WHITE)
			dfs (i);

	return 0;
}























