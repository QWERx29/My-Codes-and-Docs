// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main()
{
	cin>>n>>s;
	for(int i=0;i<s.length();i++) s[i]=(s[i]-'a'+n)%26+'a'; 
	cout<<s;
}
