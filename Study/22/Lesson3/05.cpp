#include<bits/stdc++.h>
using namespace std;
const int N=96110;
int n,m,f[N];
int find(int x)
{
	if(f[x]!=x) return f[x]=find(f[x]);
	else return f[x];
} 
void unionn(int x,int y)
{
	f[y]=x;
}
int c[N],k[N],ed[2022][2022];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++) c[i]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>ed[i][j];
    }
    for(int i=n;i>=1;i--)
    {
		for(int j=1;j<=k[i];j++)
		{
			if(ed[i][j]>i)
            {
				int r1=find(i),r2=find(ed[i][j]);
				if(r1!=r2)
                {
					unionn(r1,r2);
					c[r1]+=c[r2];
					if(c[i]>(n>>1))
                    {
						cout<<i;
						return 0;
					}
				}
			}
		}
    }
    return 0;
}
