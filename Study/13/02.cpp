#include<bits/stdc++.h>
using namespace std;
bool b[25]={0};
int tot=0,a[25],n;
bool can(int x,int y)
{
	int k=2,i=x+y;
	while(k<=sqrt(i)&&i%k!=0) k++;
	if(k>sqrt(i)) return 1;
	else return 0;
}
void search(int t)
{
	for(int i=1;i<=n;i++)
	{
		if((can(a[t-1],i)||can(a[n],i))&&(!b[i]))
		{
			a[t]=i;
			b[i]=1;
			if(t==n)
			{
				if(can(a[n],a[1])) {tot++;}
				//t=1;
			}
			else search(t+1);
			b[i]=0;
		}
		else continue;
	}
}
int main()
{
	cin>>n;
	search(1);
	cout<<tot;
	return 0;
}
