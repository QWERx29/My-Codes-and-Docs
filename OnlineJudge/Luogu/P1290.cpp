#include<bits/stdc++.h>
using namespace std;
int c,n,m;
int Euclid(int x,int y,int q)
{
	if(x==y) return q;
	if(y/x>=2) return q;
	else return Euclid(y-x,x,q^1);
}
int main()
{
	cin>>c;
	for(int i=1;i<=c;i++)
	{
		cin>>n>>m;
		if(n>m) swap(n,m);
		if(Euclid(n,m,0)==0) cout<<"Stan wins"<<endl;
		else cout<<"Ollie wins"<<endl;
	}
}
