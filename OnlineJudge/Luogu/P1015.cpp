#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],n,l,ans;
string s;
void init()
{
    cin>>n>>s;
    memset(a,0,sizeof(a));
    l=s.length();
    for(int i=0;i<l;i++) 
    {
        if(!isalpha(s[i])) a[l-i]=s[i]-'0';
        else a[l-i]=s[i]-'A'+10;
    }
}
bool check(int q[])
{
    for(int i=1;i<=l;i++) 
        if(a[i]!=a[l-i+1]) return false;
    return true;
}
void add(int a[])
{
    for(int i=1;i<=l;i++) b[l-i+1]=a[i];
    for(int i=1;i<=l;i++) a[i]+=b[i];
    for(int i=1;i<=l;i++) 
    {
        a[i+1]+=a[i]/n;
        a[i]%=n;
    }
    if(a[l+1]>0) l++;
}
int main()
{
    init();
    if(check(a)) {cout<<"STEP="<<0;return 0;}
    while(ans<=30)
    {
        ans++;
        add(a);
        if(check(a)) {cout<<"STEP="<<ans;return 0;}
    }
    cout<<"Impossible!";
    return 0;
}