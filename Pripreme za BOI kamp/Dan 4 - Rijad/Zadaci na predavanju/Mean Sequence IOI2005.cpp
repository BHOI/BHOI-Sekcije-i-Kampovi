#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char c;

inline void scanInt(int &x)
{
    x=0;
    c=0;
    while((c=getchar_unlocked())<'0');
    x=c-'0';
    while((c=getchar_unlocked())>='0'){x*=10;x+=c-'0';}
}

int main()
{
    //freopen("in.txt","r",stdin);
    int sum=0,gornja=(999999999+1),donja(-999999999-1),n,niz;
    //scanf("%d",&n);
    scanInt(n);
    for(int i=1;i<=n;i++)
    {
        scanInt(niz);
     //   printf("\n--%d %d--\n",sum,niz);
     //   printf("%d %d\n",gornja,donja);
        if (i&1)
        {
            gornja=min(gornja,niz-sum-sum);
        }
        else
        {
            donja=max(donja,sum-niz+sum);
        }
        sum=niz-sum;
    }
    printf("%d\n",max(gornja-donja+1,0));
    return 0;
}
