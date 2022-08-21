#include<bits/stdc++.h>
const int N=1.5e5+6;
using namespace std;

int n,c[N],ans[N];

void update(int x) 
{
    for(;x<=N;x+=x&-x) c[x]+=1;
}
int query(int x)
{
    int res=0;
    for(;x;x-=x&-x) res+=c[x];
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        int s=query(x+1);
        update(x+1);
        ans[s]++;
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;
    return 0;
} 