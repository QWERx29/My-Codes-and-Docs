#include<bits/stdc++.h>
using namespace std;
int s,i,n,t,k,r,w[100001],x[300002],y[300002];
int main()
{
    cin>>n;
    while(n!=0)
	{
        cin>>t>>k;
        while(k!=0)
		{
            y[++r]=t;
			cin>>x[r];
            if(!w[x[r]])s++;
            w[x[r]]++;
			k--;
        }
        while(t-y[i]>=86400)
        {
        	if(!--w[x[i++]]) s--;
		}
        cout<<s<<endl;
        n--;
    }
    return 0;
}
