// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int n,a;
int main()
{
	cin>>n;
	for(int i=n;i>=0;i--)
	{
	    cin>>a;
	    if(a!=0)
	    {
			if(i!=n&&a>0) cout<<"+";
			if(abs(a)>1||i==0) cout<<a;
			if(a==-1&&i!=0) cout<<"-";
			if(i>1) cout<<"x^"<<i;
			if(i==1) cout<<"x";
        }
    }
}