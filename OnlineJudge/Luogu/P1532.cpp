#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ind;
ll a[100000], n;
int main() 
{
    while(cin>>n) 
	{
        ind=0;
        a[++ind]=n;
        bool flag=true;
        while(flag) 
		{
            ll b[20]={0},n1=0,n2=0;
            int in=0;
            while(n) 
			{
                b[++in]=n%10;
                n/=10;
            }
            sort(b+1,b+1+in);
            for(int i=1;i<=in;i++) n1=n1*10+b[i];
            for(int i=in;i>=1;i--) n2=n2*10+b[i];
            n=n2-n1;
            for(int i=1;flag&&i<=ind;i++)
            {
            	if(a[i]==n) 
				{
                    flag=false;
                    for(int j=i;j<=ind;j++)
                        cout<<a[j]<<" ";
                }
			} 
            a[++ind]=n;
        }
        puts("");
    }
    return 0;
}

