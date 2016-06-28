#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <iostream>

using namespace std;

struct edge
{
    int x,d;
    edge(){}
    edge(int _x,int _d){x=_x;d=_d;}
};

typedef long long lint;
vector<vector<edge> > ve;
int n,m,l,a,b,c,id,tmpid,prvi,drug,trec;
lint maxim,maxio=-1;
vector <bool> vis;
vector<edge> put;
vector<lint> drvo;

int dfsi(int x,int p,lint d)
//identificira najudaljeniju tacku od nekog x
{
    if (p==-1)
    {
        maxim=-1;
        id=-1;
    }
    vis[x]=1;
    for(int i=0;i<ve[x].size();i++)
    {
        if (ve[x][i].x!=p)
        {
            dfsi(ve[x][i].x,x,d+ve[x][i].d);
        }
    }
    if (d>maxim){maxim=d;id=x;}
    return 0;
}

int dfsp(int x,int p,int fx)
//u vektor put prepise put od x do fx
//tako sto pise intove duzine do sljedeceg
{
    int tmp;
    if (x==fx){put.clear();put.push_back(edge(fx,0));return 1;}
    for(int i=0;i<ve[x].size();i++)
    {
        if (ve[x][i].x!=p)
        {
            tmp=dfsp(ve[x][i].x,x,fx);
            if (tmp==1)
            {
                put.push_back(edge(x,ve[x][i].d));
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d %d",&n,&m,&l);ve.resize(n);vis.resize(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        ve[a].push_back(edge(b,c));
        ve[b].push_back(edge(a,c));
    }
    for(int i=0;i<n;i++)
    {
        if (!vis[i])
        {
            dfsi(i,-1,0);
            tmpid=id;
            dfsi(tmpid,-1,0);
            dfsp(id,-1,tmpid);
            maxio=max(maxio,maxim);
            /*for(int i=0;i<put.size();i++)
            {
                printf("%d %d || ",put[i].x,put[i].d);
            }
            putchar('\n');*/
            lint duz=0;
            for(int i=0;i<put.size();i++)
            {
                duz+=(lint)put[i].d;
                if (duz>=maxim/2)
                {
                    prvi=put[i].x;
                    drug=(i>0)?put[i-1].x:put[i].x;
                    trec=(i<put.size()-1)?put[i+1].x:put[i].x;
                    break;
                }
            }
            dfsi(prvi,-1,0);
            drvo.push_back(maxim);
            dfsi(drug,-1,0);
            drvo.back()=min(drvo.back(),maxim);
            dfsi(trec,-1,0);
            drvo.back()=min(drvo.back(),maxim);
            //printf("%d\n",drvo.back());
        }
    }
    sort(drvo.rbegin(),drvo.rend());
    if (drvo.size()==1)printf("%lld\n",max(drvo[0],maxio));else
    if (drvo.size()==2)printf("%lld\n",max(maxio,(long long)drvo[0]+l+drvo[1]));else
        printf("%lld\n",max(maxio,max((long long)drvo[0]+drvo[1]+l,(long long)drvo[1]+drvo[2]+2*l)));
    return 0;
}
