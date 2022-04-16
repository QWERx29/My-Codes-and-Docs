#include<bits/stdc++.h>
#include<string>
#include <algorithm>
using namespace std;
string m,n;
char s1[1024],s2[1024],a[1024],b[1024];
int q,w,i,j;
int main()
{
	getline(cin,m);getline(cin,n);
	for(i=0; i<m.length(); ++i)
	{
    	s1[i]=m[i];
	}
 	for(j=0; j<n.length(); ++j)
	{
    	s2[j] = n[j];
	}
	for(int i=0;i<strlen(s1);i++)
	{
		if(s1[i]>='A'&&s1[i]<='Z') s1[i]+=32;
	}
	for(int i=0;i<strlen(s2);i++)
	{
		if(s2[i]>='A'&&s2[i]<='Z') s2[i]+=32;
	}
	for(int i=0;i<strlen(s1);i++)
	{
		if(s1[i]!=' ') a[q++]=s1[i];
	}
	for(int i=0;i<strlen(s2);i++)
	{
		if(s2[i]!=' ') b[w++]=s2[i];
	}
	if(strcmp(a,b)==0) cout<<"YES";
	else cout<<"NO";
	return 0;
}

