#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int ans[N];
int main()
{
	ios::sync_with_stdio(false);
//    freopen("1583.txt","r",stdin);
//    freopen("1583.out","w",stdout);
    int t,n;
    memset(ans,0,sizeof(ans));
    for(int m=1;m<N;m++) 
	{
    	int x=m,y=m;
    	while(x>0) 
		{
			y+=x%10;
			x/=10;
		}
    	if(ans[y]==0||m<ans[y]) ans[y]=m;
	}
	scanf("%d",&t);
	while(t--) 
	{
    	scanf("%d",&n);
    	printf("%d\n",ans[n]);
	}
	return 0;
}

