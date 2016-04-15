#include <iostream>
#include <cstdio>
#include <stack>
 
using namespace std;
 
int n, trains [10000];
stack<int> s;
 
void solve()
{
    for(;;) 
	{
		while (s.size() > 0)
			s.pop();

		for (int i = 0; i < n; i++)
		{
			cin >> trains [i];
			if (trains [i] == 0)
				return;
		}
		
		int current_index = 0;

		for (int i = 0; i < n; i++)
		{
			while (current_index < n && current_index != trains [i])
			{
				if (s.size() > 0 && s.top() == trains [i])
					break;
				
				current_index++;
				s.push(current_index);
			}

			if (s.top() == trains [i])
				s.pop();
		}

		if (s.size() == 0)
			printf ("Yes\n");
		else
			printf ("No\n");
	}
}
 
int main() 
{
    for(;;) 
	{
        scanf ("%d", &n);
        if (n == 0) 
			break;
 
        solve();
        printf("\n");
    }

	return 0;
}

