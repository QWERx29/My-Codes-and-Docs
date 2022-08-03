#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string str1 ,str2;
int main()
{
	getline(cin,s1);
	getline(cin,s2);
    int l1=s1.size(),l2=s2.size();
	for(int i=0;i<l1;i++)
    {
		if(s1[i]==' ') continue;
		s1[i]=tolower(s1[i]);
		str1+=s1[i]; 
	}
	for(int i=0;i<l2;i++)
    {
		if(s2[i]==' ') continue;
        s2[i]=tolower(s2[i]);
		str2+=s2[i]; 
	}
	if(str1==str2) cout<<"YES";
    else cout<<"NO";
	return 0;
}
