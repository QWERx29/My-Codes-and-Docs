#include<bits/stdc++.h>
using namespace std;
struct trans
{
	int v,c,t;
}a[100010]; 
int main()
{
	int x=0,m=0,n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v>>a[i].c>>a[i].t;
		m+=a[i].c;
        if(a[i].v==1)
		{
            for(int j=(i-45>0?i-45:1);j<i;j++)
			{
                if(a[j].c>=a[i].c&&a[i].t-a[j].t<=45&&a[j].v==0)
				{
                    a[j].c=0;
                    a[j].t=0;
                    m=m-a[i].c;
                    break;
                }
            }
        }
    }
	cout<<m<<endl;
    return 0;
}
