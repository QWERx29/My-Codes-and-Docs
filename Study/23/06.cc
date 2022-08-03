#include<bits/stdc++.h>

using namespace std;
const int N=100010;
const int INF=0x3f3f3f3f;
int n,k,s,ans=0;
int nxt[N],a[N],b[N],c[N],r[N],t[N],f[N],maxx[N],maxy[N];

inline void kmp(int step,int x)
{
	for(int i=1;i<=n;i++) if(a[i]==x) r[i]=x; else r[i]=0;
	for(int i=1;i<=k;i++) if(b[i]==step) t[i]=x; else t[i]=0;
	nxt[1]=0;
	for(int i=2,j=0;i<=k;i++)
	{
		while(j&&t[i]!=t[j+1]) j=nxt[j];
		if(t[i]==t[j+1]) j++;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=n;i++)
	{
		while(j&&(j==k||r[i]!=t[j+1])) j=nxt[j];
		if(r[i]==t[j+1]) j++;
		if(j==k) maxy[i-k+1]=x;
	}
}

int main()
{
	scanf("%d%d%d",&n,&k,&s);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=k;i++) scanf("%d",&b[i]),c[b[i]]=1;
    for(int i=1;i<=s;i++)
	{
        if(!c[i]) continue;
        for(int j=1;j<=n;j++) maxy[j]=INF;
        for(int j=1;j<=s;j++) kmp(i,j);
        for(int j=1;j<=n;j++) if(maxx[j]>=maxy[j]) maxx[j]=INF;else maxx[j]=maxy[j];
	}
    for(int i=1;i<=n;i++) if(maxx[i]!=INF) ans++; 
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) if(maxx[i]!=INF) printf("%d\n",i);
    return 0;
} 