#include<bits/stdc++.h>
using namespace std;
int m,l[100][100];
int main()
{
	cin>>m;
	int n=pow(2,m),k=1,mid=1;
	l[0][0]=1;
	while(k<=m)
	{
		for(int i=0;i<mid;i++)
		{
			for(int j=0;j<mid;j++)
			{
				l[i][j+mid]=l[i][j]+mid;
			}
		}
		for(int i=0;i<mid;i++)
		{
			for(int j=0;j<mid;j++)
			{
				l[i+mid][j]=l[i][j+mid];
				l[i+mid][j+mid]=l[i][j];
			}
		}
		mid*=2;
		k++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<setw(3)<<l[i][j];
		}
		cout<<endl;
	}
	return 0;
}
