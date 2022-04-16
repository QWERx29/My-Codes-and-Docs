#include<bits/stdc++.h>
using namespace std;
int i=-1,a[200];
string s1,s2;
int tree(int l,int r)
{
	int tot=0,k=++i;
	int m=s2.find(s1[k]);
	if(m>l)tot+=tree(l,m-1);
	if(m<r)tot+=tree(m+1,r);
	if(l==r)tot=1;
	a[s1[k]]=tot;
	return tot;
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>s1>>s2;
	tree(0,s1.size()-1);
	for(int i=0;i<s1.size();i++)
	{
		for(int j=1;j<=a[s1[i]];++j)
			cout<<s1[i];
		cout<<endl;
	}
	return 0;
}

