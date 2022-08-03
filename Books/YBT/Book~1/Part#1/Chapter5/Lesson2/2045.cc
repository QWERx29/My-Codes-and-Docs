#include<bits/stdc++.h>
using namespace std;
int a[25][25],n,tot,x,y; 
int main()
{
	cin>>n;
	y=n-1;tot=1;
	a[x][y]=1;
	while(tot<n*n)
    {
        while(x+1<n&&!a[x+1][y])  a[++x][y]=++tot;
        while(y-1>=0&&!a[x][y-1])  a[x][--y]=++tot;
        while(x-1>=0&&!a[x-1][y])  a[--x][y]=++tot;
        while(y+1<n&&!a[x][y+1])  a[x][++y]=++tot;
    }
    for(x=0;x<n;x++)
    {
		for(y=0;y<n;y++) cout<<a[x][y]<<" ";
		cout<<endl;
    }
	return 0;
}
