#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;

bool valid(int n,int seq[])
{
    if(n==0)return 1;
    int mini=min_element(seq,seq+n)-seq,
        maxi=max_element(seq,seq+n)-seq;
    vector<int> ve(seq,seq+n);
    sort(ve.begin(),ve.end());
    if(unique(ve.begin(),ve.end())!=ve.end())return 0;
    if(seq[mini]>n)return 1;
    if(seq[mini]<1)return 0;
    for(int i=mini;i<mini+n;i++)
        if(seq[i%n]<=n && i-mini!=seq[i%n]-seq[mini])return 0;
    return 1;
}

int replacement(int n,int gonsq[],int repsq[])
{
    if(n==0)return 0;
    vector<int> ori(n);
    int mini=min_element(gonsq,gonsq+n)-gonsq,
        maxi=max_element(gonsq,gonsq+n)-gonsq;
    for(int i=0;i<n;i++)ori[i]=i+1;
    if(gonsq[mini]<=n)
    {
        for(int i=mini;i<mini+n;i++)
            ori[i%n]=(gonsq[mini]+i-mini-1+n)%n+1;
    }
    priority_queue<pair<int,int> > pq;
    for(int i=0;i<n;i++)
        if(ori[i]!=gonsq[i])pq.push(mp(-gonsq[i],i));
    int UBC=n+1,J=0;
    while(!pq.empty())
    {
        while(UBC!=-pq.top().xx)
        {
            repsq[J++]=ori[maxi];
            ori[maxi]=UBC++;
        }
        pair<int,int> aa=pq.top();
        pq.pop();
        repsq[J++]=ori[aa.yy];
        ori[aa.yy]=UBC++;
    }
    return J;
}
const int MOD=1000000009;
long long brz(int n,int step)
{
    if(step==0)return 1;
    if(step==1)return n;
    long long tmp=brz(n,step/2);
    tmp*=tmp;tmp%=MOD;
    return (tmp*((step&1)?n:1))%MOD;
}

int countReplacement(int n,int seq[])
{
    if(!valid(n,seq))return 0;
    vector<int> ori(n);
    int mini=min_element(seq,seq+n)-seq,
        maxi=max_element(seq,seq+n)-seq;
    for(int i=0;i<n;i++)ori[i]=i+1;
    int mul;
    mul=n;
    if(seq[mini]<=n)
    {
        mul=1;
        for(int i=mini;i<mini+n;i++)
            ori[i%n]=(seq[mini]+i-mini-1+n)%n+1;
    }
    vector<int> AaA;
    for(int i=0;i<n;i++)
        if(ori[i]!=seq[i])AaA.pb(seq[i]);
    sort(AaA.begin(),AaA.end());
    int UBC=n+1,I=0;
    long long rez=1;
    while(I<AaA.size())
    {
        rez*=brz(AaA.size()-I,AaA[I]-UBC);
        rez%=MOD;
        UBC=AaA[I++]+1;
    }
    return (rez*mul)%MOD;
}

int a[100005], b[100005];
int n,t;

int main()
{
    scanf("%d",&t);
    if(t<4)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        printf("%d\n",valid(n,a));
    }
    else if(t<7)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int l;
        printf("%d ",l=replacement(n,a,b));
        for(int i=0;i<l;i++)printf("%d%s",b[i],(i==l-1)?"\n":" ");
    }
    else
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        printf("%d\n",countReplacement(n,a));
    }
    return 0;
}
