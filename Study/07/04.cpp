#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,me,w;
struct id
{
	char t;
	union
	{
		char idc[19];
		long long q;
	};
	
};
id a[10005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t;
		if(a[i].t=='i') 
		{
			for(int j=0;j<18;j++) cin>>a[i].idc[j];
		}
		else if(a[i].t=='q')
		{
			cin>>a[i].q;
		}
	}
	long long sum=0;int aveq=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].t=='i')
		{
			if((a[i].idc[16]-'0')%2) me++;
			else w++;
			
		}
		if(a[i].t=='q') 
		{
			sum+=a[i].q;aveq++;
		} 
	}
	cout<<me<<" "<<w<<" "<<sum/aveq;
	return 0;
}
