// luogu-judger-enable-o2
#include<iostream>
using namespace std;
int main()
{
	int a[101],b=0;
	for(int i=1;;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		break;
		b=i;
	}
	for(int i=b;i>=1;i--)
		cout<<a[i]<<" ";
}
