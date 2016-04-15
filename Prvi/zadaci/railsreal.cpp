/*
 * Sai Cheemalapati
 * UVA 514: Rails
 *
 */
 
#include<cstdio>
#include<stack>
 
using namespace std;
 
int n, train;
stack<int> s;
 
void solve()
{
    for(;;) 
	{
        while (s.size() > 0) 
			s.pop();
        
		int j = 0;
        
		for(int i = 0; i < n; i++) 
		{
            scanf ("%d", &train);
            if(train == 0) 
				return;
 
            while (j < n && j != train)
			{
                if (s.size() > 0 && s.top() == train) 
					break;
                j++;
                s.push(j);
            }

            if (s.top() == train) 
				s.pop();
        }

		if (s.size() == 0) 
			printf("Yes\n");
        else 
			printf("No\n");
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


