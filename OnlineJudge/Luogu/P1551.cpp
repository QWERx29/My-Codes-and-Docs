#include<bits/stdc++.h>
#define N 96110
#define ll long long
using namespace std;
int father[N],m,n,x,y,q;
int find(int x)
{
	if(father[x]!=x) return find(father[x]);
	else return father[x];
} 
void unionn(int x,int y)
{
	father[y]=x;
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) father[i]=i;
    for(int i=1;i<=m;i++)
    {
    	cin>>x>>y;
    	int r1=find(x),r2=find(y);
    	if(r1!=r2) unionn(r1,r2);
	}
//	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(find(x)==find(y)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

