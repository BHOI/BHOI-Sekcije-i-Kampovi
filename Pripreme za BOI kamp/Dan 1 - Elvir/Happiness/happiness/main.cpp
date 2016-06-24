#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

#define MAXN 200100
#define MAXC 1e12
#define ll long long int

struct node
{
    int key, val;
    node *left, *right;
    const int MAXROW = MAXC;

    node() { }

    node(int _val, node* _left, node* _right)
    {
        val = _val;
        key = 0;
        left = _left;
        right = _right;
    }

    void update(int l, int r, int p, int v);
    void update(int p, int v);
    int query(int l, int r, int p, int q);
    int query(int p, int q);
};

node *null, *st;

void node::update(int l, int r, int p, int v)
{
    if(r - l < 2)
    {
        key += p * v;
        val += v;
        return;
    }

    int m = (l + r) >> 1;
    if(p < m)
    {
        if(left == null) left = new node(0, null, null);
        left->update(l,m,p,v);
    }
    else
    {
        if(right == null) right = new node(0, null, null);
        right->update(m,r,p,v);
    }

    key = left->key + right->key;
}

void node::update(int p, int v)
{
    update(0, MAXROW, p, v);
}

int node::query(int l, int r, int p, int q)
{
    if(l > q || r <= p) return 0;
    if(l >= p && r-1 <= q) return key;
    int m = (l + r) >> 1;
    return left->query(l,m,p,q) + right->query(m,r,p,q);
}

int node::query(int p, int q)
{
    return query(0, MAXROW, p, q);
}

int coinCount, q, t, k, a [10];
ll maxCoin, tree [MAXN];
vector <ll> coins;
multiset <ll> problem;

void reset()
{
    null = new node(0, NULL, NULL);
    st = new node(0, null, null);
    null->left = null->right =  null;
    coins.clear();
    problem.clear();
    memset (tree, 0, sizeof tree);
}

int main()
{
	//freopen ("happiness10.txt", "r", stdin);
	
    reset();

	ll sumTo = 1;

    cin >> coinCount >> maxCoin;
    coins.resize(coinCount);
    for (int i = 0; i < coinCount; i++)
	{
        cin >> coins [i];
		st->upadte(coins [i], 1);
	}

    sort (coins.begin(), coins.end());

    for (int i = 1; i < coinCount; i++)
	{
        if (coins [i] > 2 * coins [i - 1] && sumTo >= a [i])
			problem.insert(a [i]);

		sumTo += a [i];
	}


	/*
	for (int i = 1; i <= 10; i++)
		st->update(i, 2);

	cout << st->query(2, 4) << endl;

	st->update (3, -1);
	cout << st->query(2, 4) << endl;
	*/

    /*
       cin >> q;

       while (t--)
       {
       cin >> q >> k;

       for (int i = 0; i < k; i++)
       cin >> a [i];

       sort (a, a + k);

       if (q == 1)
       {
       for (int i = 0; i < k; i++)
       update (
       }
       else if (q == -1)
       {

       }
       }*/


    return 0;
}

