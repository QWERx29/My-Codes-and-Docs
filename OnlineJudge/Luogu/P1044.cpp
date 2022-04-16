#include<bits/stdc++.h>
using namespace std;
#define maxn 550
int n;
int a[maxn],b[maxn],ans[maxn*20];
int gcd(int a,int b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}
void mul(int x)
{
    int k=0;
    for(int i=1;i<=ans[0];i++)
    {
        ans[i]*=x;
        ans[i]+=k;
        k=ans[i]/10;
        ans[i]%=10;
    }
    while(k)
    {
        ans[++ans[0]]=k%10;
        k/=10;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        a[i-1]=i+n;
        b[i-1]=i;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(b[j]==1) continue;
            int d=gcd(a[i],b[j]);
            if(d!=1)
            {
                a[i]/=d;
                b[j]/=d;
            }
            if(a[i]==1) break;
        }
    }
    ans[0]=ans[1]=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==1) continue;
        mul(a[i]);
    }
    for(int i=ans[0];i>=1;i--) cout<<ans[i]; 
}

