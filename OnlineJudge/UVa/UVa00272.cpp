#include<bits/stdc++.h>
#define N 96110
#define ll long long
using namespace std;
int main()
{
	int c,q=1;
	ios::sync_with_stdio(false);
 	freopen("272.in","r",stdin);
	freopen("272.out","w",stdout);
	while((c=getchar())!=EOF)
	{
		if(c=='"')
		{
			printf("%s",q?"``":"''");
			q=!q;
		}
		else printf("%c",c);
	}
	return 0;
}

