#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    s.clear();
    string s1[1000];
    int n=0;
    while(cin>>s) s1[n++]=s;
    for(int i=0;i<n;i++)
    {
        if(i)
        cout<<",";
        cout<<s1[i].size();
    }
    cout<<endl;
	return 0;
}