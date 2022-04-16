#include<bits/stdc++.h>
using namespace std;
int temp,sum;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	while(scanf("%d",&temp)==1)
	{
		sum+=temp;
	}
	
	printf("%d",sum);
	fclose(stdin);fclose(stdout);
	return 0;
}
