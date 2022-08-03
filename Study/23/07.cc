#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll MOD=1e9+7;
const int N=114514*10;

int n,nxt[N],ans[N];ll cnt;char a[N];

int main()
{
    ios::sync_with_stdio(false);
    int T,i,j;
    cin>>T;
    while(T--)
    {
        cin>>a;
        n=strlen(a);
        memset(nxt,0,sizeof(nxt));
        j=0;ans[0]=0;ans[1]=1;
        
        for(i=1;i<n;i++)
        {
            while(j&&(a[i]!=a[j])) j=nxt[j];
            j+=(a[i]==a[j]);nxt[i+1]=j;ans[i+1]=ans[j]+1;
        }
        
        j=0;cnt=1;
        for(i=1;i<n;i++)
        {
            while(j&&(a[i]!=a[j])) j=nxt[j];
            j+=(a[i]==a[j]);
            while((j<<1)>(i+1)) j=nxt[j];
            cnt=(cnt*(ll)(ans[j]+1))%MOD;
        }
        cout<<cnt<<endl;
    }
}