#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

int t, n, k, p, coins [1000];
string sign;

set <int> less_than;
set <int> greater_than;
set <int> same;

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n >> k;

		less_than.clear();
		greater_than.clear();
		same.clear();

		for (int i = 1; i <= n; i++)
		{
			less_than.insert(i);
			greater_than.insert(i);
		}

		while (k--)
		{
			cin >> p;

			for (int i = 0; i < 2 * p; i++)
				cin >> coins [i];

			cin >> sign;

			if (sign == "=")
			{
				for (int i = 0; i < 2 * p; i++)
				{
					less_than.erase(coins [i]);
					greater_than.erase(coins [i]);
					same.insert(coins [i]);
				}
			}
			else if (sign == "<")
			{
				for (int i = 0; i < p; i++)
				{
					less_than.insert(coins [i]);
					greater_than.erase(coins [i]);
				}
				for (int i = p; i < 2 * p; i++)
				{
					greater_than.insert(coins [i]);
					less_than.erase(coins [i]);
				}
			}
			else if (sign == ">")
			{
				for (int i = 0; i < p; i++)
					greater_than.insert(coins [i]);
				for (int i = p; i < 2 * p; i++)
					less_than.insert(coins [i]);
			}

			for (int s : same)
			{
				greater_than.erase(s);
				less_than.erase(s);
			}
		}

		//if ((less_than.size() == 1 || greater_than.size() == 1) && less_than.size() != greater_than.size())
		
		if ((less_than.size() == 1 && greater_than.size() == 1) && (*less_than.begin() != *greater_than.begin()))
			cout << 0 << endl << endl;
		else if ((less_than.size() == 1 && greater_than.size() == 1) && (*less_than.begin() == *greater_than.begin()))
			cout << *less_than.begin() << endl << endl;
		else if ((less_than.size() == 1 || greater_than.size() == 1))
			cout << ((less_than.size() == 1) ? *less_than.begin() : *greater_than.begin()) << endl << endl;
		else
			cout << 0 << endl << endl;
	}



	return 0;
}

