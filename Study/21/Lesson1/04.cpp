#include<bits/stdc++.h>
using namespace std;
string s1,s2;
void calc(int l1,int r1,int l2,int r2)
{
	int m=s2.find(s1[l1]);
	if(m>l2) calc(l1+1,l1+m-l2,l2,m-1);
	if(m<r2) calc(l1+m-l2+1,r1,m+1,r2);
	cout<<s1[l1];
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>s2>>s1;
    calc(0,s1.length()-1,0,s2.length()-1);
    cout<<endl;
    return 0;
}
