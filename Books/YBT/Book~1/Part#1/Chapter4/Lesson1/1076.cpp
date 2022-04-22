#include<bits/stdc++.h>
using namespace std;
int n,t,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int h,l;
        cin>>h>>l;
        if((h>=90&&h<=140)&&(l>=60&&l<=90)) t++;
        else t=0;
        m=max(m,t);
    }
    cout<<m<<endl;
    return 0;
}