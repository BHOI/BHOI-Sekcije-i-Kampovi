#include <bits/stdc++.h>

using namespace std;

int r,l;
typedef long long lint;
lint b;
vector<lint> prefix;

bool moze(int I,int J)
{
    I++;J++;
    return (prefix[J]+prefix[I-1]-
            prefix[(I+J)/2-((J-I+1)&1)]-prefix[(I+J)/2])<=b;
}

int main()
{
    scanf("%d %d %lld",&r,&l,&b);
    prefix.resize(r+1);
    for(int i=0;i<r;i++)
    {
        scanf("%lld",&prefix[i+1]);
        prefix[i+1]+=prefix[i];
    }
    int I=0,J=0,maxio=0;
    while(J<r)
    {
        while(J<r && moze(I,J))J++;
        maxio=max(maxio,J-I);
        I++;
    }
    printf("%d\n",maxio);
    return 0;
}
