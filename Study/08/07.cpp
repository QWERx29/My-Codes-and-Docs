#include<bits/stdc++.h>
using namespace std;
const int p=100001;
int n,m,k;
int x[p],y[p],data[p];
int numbery[p];
int *t[p];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>x[i]>>y[i]>>data[i];
        numbery[y[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        t[i]=new int[numbery[i]];
    }
    for(int i=1;i<=k;i++)
    {
        *t[y[i]]=data[i];
        t[y[i]]++;
	}
    for(int i=1;i<=m;i++)
    {
        t[i]-=numbery[i];
        for(int j=1;j<=numbery[i];j++)
        {
            cout<<*t[i]<<' ';
            t[i]++;
        }
    }
    return 0;
}
