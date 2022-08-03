#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int len=s.size();
		if(islower(s[0]))s[0]=(char)(toupper(s[0]));
		cout<<s[0];
		for(int j=1;j<len;j++)
		{
			if(isupper(s[j]))s[j]=(char)(tolower(s[j]));
			cout<<s[j];
		}
		cout<<"\n";
	}
	return 0;
}