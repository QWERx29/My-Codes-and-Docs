#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("copycat.in","r",stdin);
	freopen("copycat.out","w",stdout);
	int n;
	char str[3000];
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		scanf("%s",&str);
		printf("%s\n",str);
	}
	return 0;
}