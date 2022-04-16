#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086];
bool cri(int a)
{
	if(a<2) return false;
	if(a==2) return true;
	if(a>2)
	{
		for(int i=2;i<=sqrt(a);++i)
		{
			if(a%i==0) return false;
			else return true;
		}
	}
}
int* find()
{
	for(int i=1;i<=m;i++)
	{
		if(cri(a[i])) return &a[i];
		
	}
	return NULL;
}
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	int *p=find();
	if(p!=NULL) cout<<"YES"<<endl<<*p<<endl;
	else cout<<"NULL";
	return 0;
}
