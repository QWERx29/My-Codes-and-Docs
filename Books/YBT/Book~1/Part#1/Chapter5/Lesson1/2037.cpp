#include<bits/stdc++.h>
using namespace std;
int a[1020],n,m,f,t,s;
int main()
{
    cin>>n>>m;
	do
    {
		++t;
        if (t==n+1) t=1;
        if (a[t]==0) ++s;
        if (s==m)
        {
			s=0;
            cout<<t<<" ";
            a[t]=1;
            f++;
        }
    }while(f!=n);
    return 0;
}
