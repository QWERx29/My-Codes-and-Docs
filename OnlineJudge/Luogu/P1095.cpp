// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int m,s,t,a[300005];
int main()
{
	cin>>m>>s>>t;
	for(int i=1;i<=t;i++) 
	{
		if(m>=10){a[i]=a[i-1]+60;m-=10;}
		else{a[i]=a[i-1];m+=4;}
	}
	for(int i=1;i<=t;i++)
    {
	    a[i]=max(a[i],a[i-1]+17);
	    if(a[i]>=s){cout<<"Yes"<<endl<<i;return 0;}
    }
    cout<<"No"<<endl<<a[t];
}
