#include<bits/stdc++.h>
using namespace std;
enum dir
{
	_up=0,_down=1,_left=2,_right=3
 } ;
int n,x,y,d;
int a[10086][10086],sum;
int main()
{
	cin>>n>>x>>y>>d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if (d==_up)		
	{
		for (int i=x; i>=1; i--)  sum+=a[i][y];
	}	
	if (d==_down)
	{
		for (int i=x; i<=n; i++)  sum+=a[i][y];
	}			
	if (d==_left)
	{
		for (int i=y; i>=1; i--)   sum+=a[x][i];
	}			
	if (d==_right)		
	{
		for (int i=y; i>=n; i++)  sum+=a[x][i];
	}   
	cout<<sum;
	return 0;
}

