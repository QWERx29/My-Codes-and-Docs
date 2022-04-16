#include<bits/stdc++.h>
using namespace std;
int n,s,f;
int main()
{
    scanf("%d",&n);
    if (n<0) 
	{ 
		cout<<"-"; 
		n=abs(n);
	}
    while (n>0) 
	{  
		s=n%10; n/=10;
	    if (s>0) f=1; 
	    if (f>0) cout<<s; 
	}
	cout<<endl;
    return 0;
}

