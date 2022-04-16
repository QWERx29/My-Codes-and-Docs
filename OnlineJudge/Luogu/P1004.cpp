#include<stdio.h>
#include <iostream>
#define MAXN 55
using namespace std;
int a[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
int max_four(int a,int b,int c,int d)
{
    if(b>a) a=b;
    if(c>a) a=c;
    if(d>a) a=d;
    return a;
}
int main()
{
    int n;
    int i,j,x,y,k,l;
    cin>>n;
    while(scanf("%d%d%d",&x,&y,&k),x) a[x][y]=k;
    for(i=1;i<=n;i++) 
	{
		for(j=1;j<=n;j++)
		{ 
    		for(k=1;k<=n;k++)  
    		{
				for(l=1;l<=n;l++)
				{
					if(i==k&&j==l)
    					dp[i][j][k][l]=max_four(dp[i][j-1][k-1][l],dp[i-1][j][k][l-1],dp[i][j-1][k][l-1],dp[i-1][j][k-1][l])+a[i][j];
    				else
    					dp[i][j][k][l]=max_four(dp[i][j-1][k-1][l],dp[i-1][j][k][l-1],dp[i][j-1][k][l-1],dp[i-1][j][k-1][l])+a[i][j]+a[k][l];
				}
			}
		}
	}	    
	cout<<dp[n][n][n][n]<<endl;
    return 0;
}

