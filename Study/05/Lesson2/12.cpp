#include<iostream> 
using namespace std;
int main()
{
	int n,a[10000][4],x,y,sum=-2;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
	}
	cin>>x>>y;
	for(i=0;i<n;i++)
	{
		if(x>=a[i][0]&&x<=a[i][2]+a[i][0]&&y>=a[i][1]&&y<=a[i][3]+a[i][1])
		    sum=i;
	}
	cout<<++sum;
	return 0;
 } 
