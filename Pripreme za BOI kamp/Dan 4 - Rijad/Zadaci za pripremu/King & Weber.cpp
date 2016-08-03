#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;
string _o[]={"parallel", "intersect", "unknown","Waterloo"};
map<string,int> mapa;
vector<int> vis;
vector<int> dist;
vector<vector<pair<int,int> > > ve;
char a[500],b[500],s[500];
int n,m,q,a_inx,b_inx,c;

bool dfs(int x,int c,int inx)
{
    vis[x]=inx;dist[x]=c&1;
    for(int i=0;i<ve[x].size();i++)
    {
        if(vis[ve[x][i].xx]==-1)
            if(!dfs(ve[x][i].xx,c+ve[x][i].yy,inx))return 0;
        //printf("%d %d\n",dist[ve[x][i].xx]&1,(dist[x]+ve[x][i].yy)&1);
        if((dist[ve[x][i].xx]&1)!=((dist[x]+ve[x][i].yy)&1))return 0;
    }
    return 1;
}

int main()
{
	scanf("%d %d",&m,&q);ve.resize(2*m+1);
	n=0;
	for(int i=0;i<m;i++)
    {
        scanf(" %s %s %s",a,b,s);
        if(!mapa[a]){mapa[a]=++n;}
        if(!mapa[b]){mapa[b]=++n;}
        if(string(s)==_o[0])c=0;else c=1;
        a_inx=mapa[a];b_inx=mapa[b];
        ve[a_inx].pb(mp(b_inx,c));
        ve[b_inx].pb(mp(a_inx,c));
    }
    vis.resize(n+1,-1);
    dist.resize(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==-1)if(!dfs(i,0,i)){printf("%s\n",_o[3].c_str());return 0;};
    }
    while(q--)
    {
        scanf(" %s %s",a,b);
        a_inx=mapa[a];b_inx=mapa[b];
        if(vis[a_inx]!=vis[b_inx] || vis[a_inx]==-1)printf("%s\n",_o[2].c_str());else
        printf("%s\n",_o[((dist[a_inx]-dist[b_inx])%2+2)&1].c_str());
    }
    return 0;
}
