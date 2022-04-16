#include<iostream>
using namespace std;
int main()
{
	int l,r,sum;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		int k=i;
		while(k!=0)
		{
			if(k%10==2) sum++;
			k/=10;
		}
		
	}	
	cout<<sum;
	return 0;
}
