#include<bits/stdc++.h>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;
char a[256],b[256];
int main()
{
    cin>>a;
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        if(a[i]=='A') b[i]='T';
        if(a[i]=='T') b[i]='A';
        if(a[i]=='C') b[i]='G';
        if(a[i]=='G') b[i]='C';
    }
    for(int i=0;i<len;i++) cout<<b[i];
}