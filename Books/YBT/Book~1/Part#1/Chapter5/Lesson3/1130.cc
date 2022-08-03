#include<bits/stdc++.h>
using namespace std;
string s;
bool flag=false;
int letters[26];
int main()
{
    cin>>s;
    int l=s.length();
	for(int i=0;i<l;i++) letters[s[i]-'a']++;
	for(int i=0;i<l;i++)
	{
		if(letters[s[i]-'a']==1)
		{
			cout<<s[i]<<endl;
			flag=true;
			break;
		}
	}
	if(flag==false) cout<<"no"<<endl;
    return 0;
}