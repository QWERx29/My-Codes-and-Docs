#include<bits/stdc++.h>
using namespace std;
char c[10086];
int n,s,a[10086];
int main()
{
	scanf("%s",c);
	n=strlen(c);
	cin>>s;
	for(int i=0;i<n;i++) a[i]=c[i]-'0';
	for(int i=0;i<s;++i) 
	{
		for(int j=0;j<n-1;++j)
		{
			if(a[j]>a[j+1]) 
			{
        		for (int k=j;k<n-1;++k) a[k]=a[k+1];
				break;
			}
		}
		--n;
    }
    int e;
    for(e=0;e<n;e++) {if(a[e]!=0) break;}
	for(int i=e;i<n;i++) cout<<a[i];
	return 0;
}

