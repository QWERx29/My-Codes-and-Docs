#include<bits/stdc++.h>
using namespace std;
int a[10086],n;
void print(int q)
{
	if(q==1) return;
	for(int i=2;i<=q;i++)
	{
		if(a[i]<a[i-1]) return;
	}
	//cout<<n<<"=";
	cout<<a[1];
	for(int i=2;i<=q;i++)
	{
		if(a[i]!=0)
		{
			cout<<'+'<<a[i];
		}
	}
	cout<<endl;
}
void search(int w,int q)
{
	for(int i=1;i<=w;i++)
	{
		a[q]=i;
		if(w-i==0) print(q);
		else search(w-i,q+1);
	}
}
int main()
{
	cin>>n;
	search(n,1);
	return 0;
}



