#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

const int MAXV		= 100000;

const int DFS_WHITE =	   0;
const int DFS_GREY  = 	   1;
const int DFS_BLACK = 	   2;

string toString(vector <int> v)
{
	stringstream ss;
	
	if (!v.empty())
	{
		ss << v [0];
		for (int i = 1; i < v.size(); i++)
			ss << " " << v [i];
		return ss.str();
	}

	return "";
}

//<graf>
struct Edge
{
	int v, w;

	Edge() { } 
	Edge(int _v, int _w) { v = _v; w = _w; }
};

vector <Edge> graph [MAXV];

int color [MAXV];
int indeg [MAXV];
//</graf>

//<topsort>
vector <int> topsort;

void topDFS(int u)
{
	cout << "entering node " << u << endl;
	color [u] = DFS_GREY;

	for (auto next : graph [u])
		if (color [next.v] == DFS_WHITE)
			topDFS(next.v);
	
	topsort.push_back(u);

	color [u] = DFS_BLACK;
	cout << "exiting node " << u << endl;
}

void khan(int v)
{
	queue <int> q;
	
	for (int i = 1; i <= v; i++)
		if (indeg [i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		topsort.push_back(u);
		for (edge next : graph [u])
		{
			indeg [next.v]--;
			if (indeg [next.v] == 0)
				q.push(next.v);
		}
	}
}
//</topsort>

int main()
{
	freopen ("toposort.txt", "r", stdin);
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		indeg [b]++;
		graph [a].emplace_back(b, 0);
	}
	
	topsort.clear();
	for (int i = 1; i <= v; i++)
		if (color [i] == DFS_WHITE)
			topDFS(i);
	reverse(topsort.begin(), topsort.end());
	cout << toString(topsort) << endl;


	return 0;
}
























