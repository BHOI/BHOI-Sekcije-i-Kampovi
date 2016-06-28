#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;

int m,n,l,k;
vector<int> c;
vector<vector<int> > bor,mat,moze;

int main()
{
 //freopen("in.txt","r",stdin);
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&l);
	moze.resize(n);
	c.resize(l);
	for(int i=0;i<l;i++)scanf("%d",&c[i]),c[i]--;
	bor.resize(m);
	mat.assign(m,vector<int>(m,1<<29));
	for(int i=0;i<m;i++)
    {
        scanf("%d",&k);
        bor[i].resize(k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&bor[i][j]);
            bor[i][j]--;
            moze[bor[i][j]].pb(i);
        }
        for(int j=0;j<i;j++)
        {
            int sz1=bor[i].size(),sz2=bor[j].size();
            for(int k=0;k<sz1;k++)
                for(int y=0;y<sz2;y++)
                    if(bor[i][k]==bor[j][(y+1+sz2)%sz2] &&
                    bor[i][(k+1+sz1)%sz1]==bor[j][y])
                            mat[i][j]=mat[j][i]=1;
        }
    }
    for(int i=0;i<m;i++)mat[i][i]=0;
    for(int k=0;k<m;k++)
        for(int j=0;j<m;j++)
            for(int i=0;i<m;i++)
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
//    for(int i=0;i<m;i++,cout.operator<<(endl))
//        for(int j=0;j<m;j++)
//            cout<<setw(5)<<mat[i][j];
    int minio=1<<29,mini{};
    for(int i=0;i<m;i++)
    {
        int ukup(0);
        for(int j=0;j<l;j++)
        {
            int mki=1<<29;
            for(int k=0;k<moze[c[j]].size();k++)
            {
                mki=min(mki,mat[moze[c[j]][k]][i]);
            }
            ukup+=mki;
        }
        if(minio>ukup){minio=ukup,mini=i+1;}
    }
    printf("%d\n%d\n",minio,mini);
    return 0;
}
