#include<bits/stdc++.h>
using namespace std;
vector<int> pile[30];
int n;
int find(int a,int &h)
{
	int p=-1;
	for(p=0;p<n;p++)
	{
		for(h=0;h<pile[p].size();h++)
		{
			if(pile[p][h]==a) return p;
		}
	}
	return -1;
}
void clear(int p,int h)
{
	vector<int>&s=pile[p];
	for(size_t i=h+1;i<s.size();i++) pile[s[i]].push_back(s[i]);
	s.resize(h+1);
}
void onto(int p,int h,int q)
{
	vector<int>&s=pile[p];
	for(size_t i=h;i<s.size();i++) pile[q].push_back(s[i]);
	s.resize(h);
}
void print()
{
	for(int i=0;i<n;i++)
	{
		cout<<i<<": ";
		for(size_t j=0;j<pile[i].size();j++) cout<<pile[i][j]<<" ";
		cout<<endl;
	}
}
int main()
{
	int a,b;string s1,s2;
	cin>>n;
	for(int i=0;i<n;i++) pile[i].push_back(i);
	while(cin>>s1>>a>>s2>>b)
	{
		int pa,pb,ha,hb;
		pa=find(a,ha);pb=find(b,hb);
		if(pa==pb) continue;
		if(s2=="onto") clear(pb,hb);
		if(s1=="move") clear(pa,ha);
		onto(pa,ha,pb);
	}
	print();
	return 0;
}
