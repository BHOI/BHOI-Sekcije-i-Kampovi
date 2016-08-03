#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
using namespace std;
struct tri
{
    vector<pair<int,int> > xc;
    tri(){}
    tri(int _x,int _x1,int _x2,int _x3,int _x4,int _x5)
    {
        xc.pb(mp(_x,_x1));
        xc.pb(mp(_x2,_x3));
        xc.pb(mp(_x4,_x5));
        sort(xc.begin(),xc.end());
    }
};
vector<vector<char> > plo;
vector<tri> svi;

void pozovi(int n,int x,int y,int a,int b)
{
  //  printf("%d %d %d %d %d\n",n,x,y,a,b);
    if(n==0)return;
    int x1=(1<<n)/2+a,y1=(1<<n)/2+b;
    if(x<x1 && y<y1)
    {
        svi.pb(tri(x1,y1,x1-1,y1,x1,y1-1));
        pozovi(n-1,x,y,a,b);
        pozovi(n-1,x1,y1,x1,y1);
        pozovi(n-1,x1-1,y1,a,y1);
        pozovi(n-1,x1,y1-1,x1,b);
    }
    if(x<x1 && y>=y1)
    {
        svi.pb(tri(x1,y1,x1-1,y1-1,x1,y1-1));
        pozovi(n-1,x,y,a,y1);
        pozovi(n-1,x1,y1,x1,y1);
        pozovi(n-1,x1-1,y1-1,a,b);
        pozovi(n-1,x1,y1-1,x1,b);
    }
    if(x>=x1 && y<y1)
    {
        svi.pb(tri(x1,y1,x1-1,y1-1,x1-1,y1));
        pozovi(n-1,x,y,x1,b);
        pozovi(n-1,x1,y1,x1,y1);
        pozovi(n-1,x1-1,y1-1,a,b);
        pozovi(n-1,x1-1,y1,a,y1);
    }
    if(x>=x1 && y>=y1)
    {
        svi.pb(tri(x1,y1-1,x1-1,y1-1,x1-1,y1));
        pozovi(n-1,x,y,x1,y1);
        pozovi(n-1,x1,y1-1,x1,b);
        pozovi(n-1,x1-1,y1-1,a,b);
        pozovi(n-1,x1-1,y1,a,y1);
    }
    return;
}

void placeTile(int n, int x, int y/*, int pos[][6]*/)
{
    svi.clear();
    pozovi(n,x,y,0,0);
    for(int i=0;i<svi.size();i++)
    {
        for(int j=0;j<3;j++)
        {
           /* pos[i][j*2]=svi[i].xc[j].yy;
            pos[i][j*2+1]=svi[i].xc[j].xx;*/
		if(j)printf(" ");
        	printf("%d %d",svi[i].xc[j].xx,svi[i].xc[j].yy);
        }
        puts("");
    }
    return;
}
int main()
{
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
	placeTile(n,x,y);
	return 0;
}
