#include<bits/stdc++.h>
using namespace std;
char t[45],ct[40][45];
int n;
int main()
{
    cin>>n;
	for(int i=1;i<=n;++i) cin>>ct[i];
	for(int i=1;i<n;++i)
	{
		int k=i;
		for(int j=i+1;j<=n;j++)
		{
			if(strcmp(ct[k],ct[j])>0) k=j;
		}
		strcpy(t,ct[i]);
		strcpy(ct[i],ct[k]);
		strcpy(ct[k],t);
	}
	for(int i=1;i<=n;++i)
		cout<<ct[i]<<endl;
	return 0;
}
