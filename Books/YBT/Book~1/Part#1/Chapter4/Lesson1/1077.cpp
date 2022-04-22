#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a%10-a/1000-a/100%10-a/10%10>0) m++;
    }
    cout<<m<<endl;
    return 0;
}