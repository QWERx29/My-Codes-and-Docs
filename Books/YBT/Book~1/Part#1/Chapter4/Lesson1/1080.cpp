#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    for(int i=2;;i++)
    {
        if((a%i==b%i)&&(a%i==c%i)&&(b%i==c%i)) 
        {
            cout<<i;
            return 0;
        }
    }
}