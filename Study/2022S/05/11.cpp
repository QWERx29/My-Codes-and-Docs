#include<bits/stdc++.h>
using namespace std;
const int N=105;
const double eps=1e-6;

double a[N][N];
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		int pos=i;
		for(int j=i+1;j<=n;j++)
			if(a[j][i]>a[pos][i]) pos=j;
		if(pos!=i) 
			for(int j=1;j<=n+1;j++) swap(a[i][j],a[pos][j]);
		if(fabs(a[i][i])<=eps)
		{
			cout<<"No Solution\n";
			return 0;
		}
		for(int j=i+1;j<=n;j++)
		{
			double tmp=a[j][i]/a[i][i];
			for(int k=i;k<=n+1;k++)
				a[j][k]-=a[i][k]*tmp;
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>i;j--)
			a[i][n+1]-=a[i][j]*a[j][n+1];
		a[i][n+1]/=a[i][i];
	}
	for(int i=1;i<=n;i++) cout<<fixed<<setprecision(2)<<a[i][n+1]<<endl;
	return 0;
}