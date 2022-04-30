#include<bits/stdc++.h>
using namespace std;
const int N=10086;
int a[N],b[N],c[N],n,m,x,maxn,i=1;
int main()
{
    while(cin>>a[i])
    {
        maxn=0;
        for(int j=1;j<=i-1;j++)
        {
            if(a[j]>=a[i]) maxn=max(maxn,b[j]);
        }
        b[i]=maxn+1;
        m=max(m,b[i]);
        x=0;
        for(int k=1;k<=n;k++)
        {
            if(c[k]>=a[i])
            {
                if(x==0) x=k;
                else if(c[x]>c[k]) x=k;
            }
        }
        if(x==0) {n++;x=n;}
        c[x]=a[i];
        i++;
    }
    cout<<m<<endl<<n;
    return 0;
}