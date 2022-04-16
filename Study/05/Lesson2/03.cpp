#include<bits/stdc++.h>
using namespace std;
char t[21],ct[15][25];
int main()
{
	for(int i=1;i<=10;++i) cin>>ct[i];
	for(int i=1;i<=9;++i)
	{
		int k=i;
		for(int j=i+1;j<=10;j++)
		{
			if(strcmp(ct[k],ct[j])>0) k=j;
		}
		strcpy(t,ct[i]);
		strcpy(ct[i],ct[k]);
		strcpy(ct[k],t);
	}
	for(int i=1;i<=10;++i)
		cout<<ct[i]<<endl;
	return 0;
}

