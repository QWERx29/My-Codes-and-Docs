#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[27]={0},a[1000],cnt=0;
char str[1000];
int n;
void print()
{
	cnt++;
	for(int i=1;i<=n;i++)
	{
		printf("%c",a[i]+96);
	}
	cout<<endl;
}
void dfs(int t)
{
	if(t==n+1) print();
	for(int i=1;i<=26;i++)
	{
		if(f[i]>0)
		{
			a[t]=i;
			f[i]--;
			dfs(t+1);
			f[i]++;
		}
	}
}

int main()
{
	cin>>n;
	cin>>str;
	for(int i=0;i<n;i++)
	{
		f[str[i]-'a'+1]++;
	}
	dfs(1);
	cout<<cnt;
	return 0;
}

