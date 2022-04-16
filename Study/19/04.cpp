#include<bits/stdc++.h>
using namespace std;
int s[10086],a[10086];
int top,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	top=0;
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		while(cur<=a[i]) s[++top]=cur++;
		if(s[top]==a[i]) --top;
		else
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}

