// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int prime[10000005],vis[10000005];
bool pp[10000005];
bool pal(int n)
{
    int i=n,m=0;
    while(i!=0)
    {
        m=m*10+i%10;
        i/=10;
    }
    if(m==n) return true;
    else return false;
}
int main()
{
	int a,b,cnt=0;
	cin>>a>>b;
	if(b>10000000) b=10000000;
    for(int i=2;i<=b;i++)
    {
        if(!vis[i]) prime[cnt++]=i,pp[i]=1;
        for(int j=0;j<cnt&&i*prime[j]<=b;j++)
        {
            vis[i*prime[j]]=i;
            if(i%prime[j]==0) break;
        }
    }
	for(int i=a;i<=b;i++)
	{
	    if(i>10000000) break;
		if(pal(i)==true&&pp[i]) cout<<i<<endl;
	}
}
