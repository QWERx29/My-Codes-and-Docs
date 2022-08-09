#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
typedef pair<int,int> pii;
priority_queue<pii> pq;
int n,m,p,t[N],ans,cnt;
int in[N],re[N],nxt[N];

int main()
{
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++) re[i]=p+1;
    for(int i=1;i<=p;i++) cin>>t[i];
    for(int i=p;i>0;i--) nxt[i]=re[t[i]],re[t[i]]=i;
    for(int i=1;i<=p;i++)
    {
        if(!in[t[i]]) 
        {
            if(cnt==m) 
            {
                in[pq.top().second]=0;
                pq.pop();
                --cnt;
            }
            in[t[i]]=1;
            ++ans,++cnt;

        }
        pq.push(pii(nxt[i],t[i]));
    }
    cout<<ans;
    return 0;
}
