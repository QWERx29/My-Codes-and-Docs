#include<bits/stdc++.h>
using namespace std;
const int N=200050;
int n,r,q,s[N],a[N],b[N],c[N],d[N];
bool cmp(int x,int y)
{
	if(c[x]==c[y]) return x<y;
	return c[x]>c[y];
}
void merge()
{
	int i=1,j=1;
	s[0]=0;
	while(i<=a[0]&&j<=b[0])
	{
		if(cmp(a[i],b[j])!=0) s[++s[0]]=a[i++];
		else s[++s[0]]=b[j++];
    }
    while(i<=a[0]) s[++s[0]]=a[i++];
    while(j<=b[0]) s[++s[0]]=b[j++];
}
int main()
{
	cin>>n>>r>>q;
	n*=2;
	for(int i=1;i<=n;i++) s[i]=i;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>d[i];
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=r;i++)
	{
		a[0]=b[0]=0;
		for(int j=1;j<=n;j+=2)
		{
			if(d[s[j]]>d[s[j+1]])
			{
				c[s[j]]++;
				a[++a[0]]=s[j];
				b[++b[0]]=s[j+1];
		    }
		    else
		    {
				c[s[j+1]]++;
				a[++a[0]]=s[j+1];
				b[++b[0]]=s[j];
            }
		}
		merge();
	}
	cout<<s[q];
}
