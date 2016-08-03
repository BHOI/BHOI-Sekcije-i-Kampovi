#include <algorithm>
#include <bitset>
#include <cctype>
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

int n;
vector<int> ve,a,ve2;
vector<pair<int,int> > rj;
int sum=0;

int main()
{
    scanf("%d",&n);
    ve.resize(n);
    a.resize(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ve[i]);
        sum+=ve[i];
    }
    ve2=ve;
    //srednja vrijednost
    int prs=sum/n;

    bool yes=0;
    //koristimo neoptimalan algoritam samo kako bi osobine
    //rjesenja napravili, tacnije koliko sa svakog treba prebaciti ikada
    //rj.pb su zakomentarisana jer nije optimalno
    while (!yes)
    {
        if(ve[0]>prs)
        {
            /*rj.pb(mp(1,ve[0]-prs));*/a[0]+=(ve[0]-prs);
            ve[1]+=ve[0]-prs;
            ve[0]=prs;
        }
        for(int i=1; i<n-1; i++)
        {
            if(ve[i]>prs)
            {
                //rj.pb(mp(i+1,(ve[i]-prs-1)/2+1));
                a[i]+=((ve[i]-prs-1)/2+1)*2;
                ve[i-1]+=(ve[i]-prs-1)/2+1;
                ve[i+1]+=(ve[i]-prs-1)/2+1;
                ve[i]-=((ve[i]-prs-1)/2+1)*2;
            }
        }
        if(ve[n-1]>prs)
        {
            /*rj.pb(mp(n,ve[n-1]-prs));*/a[n-1]+=ve[n-1]-prs;
            ve[n-2]+=ve[n-1]-prs;
            ve[n-1]=prs;
        }
        for(int i=0; i<n; i++)
        {
            if(ve[i]!=prs)break;
            if(i==n-1)
            {
                yes=1;
                break;
            }
        }
    }
	//izbacujemo redudantne poteze, tj. poteze koji rezultiraju 
	//u rasporedu koji je identican pocetnom, a to je ako isti broj
	//rasporedimo sa svake hrpe
    while (1)
    {
        int maxio=0;
        for(int i=0; i<n; i++)
            maxio=min(a[i],maxio);
        if(maxio==0)break;
        else
			for(int i=0; i<n; i++)
				a[i]-=maxio;
    }
    ve=ve2;//vracamo na pocetne hrpe
    int maxio;
	//odaberimo sada hrpe koje sto prije mozemo rijesiti, sto ce greedyem
	//garantovati najbrze rjesavanje problema, ostavljeno citaocu da dokaze
    while (1)
    {
        maxio=0;
        for(int i=0; i<n; i++)
        {
            if (ve[i]>ve[maxio] && a[i])maxio=i;
        }
        {
            int i=maxio;
            if((i==0 || i==n-1) && a[i] && ve[i])
            {
                int vr=min(a[i],ve[i]);
                a[i]-=vr;
                ve[i]-=vr;
                ve[(i==0)?1:(n-2)]+=vr;
                rj.pb(mp(i+1,vr));
            }
            else if(a[i] && ve[i])
            {
                int vr=min(a[i],((ve[i])&1)?(ve[i]-1):(ve[i]));
                a[i]-=vr;
                ve[i]-=vr;
                ve[i+1]+=vr/2;
                ve[i-1]+=vr/2;
                rj.pb(mp(i+1,vr/2));
            }
        }
        int j;
        for(j=0; j<n; j++)if(a[j])break;
        if(j==n)break;
    }
    printf("%d\n",rj.size());
    for(int i=0; i<rj.size(); i++)
        printf("%d %d\n",rj[i].xx,rj[i].yy);
    return 0;
}
