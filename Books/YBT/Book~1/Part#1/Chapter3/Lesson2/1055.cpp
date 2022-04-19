#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%4==0)
    {
        if(n%100==0)
        {
            if(n%400==0) cout<<"Y";
            else cout<<"N";
        }
        else cout<<"Y";
    }
    else cout<<"N";

    return 0;
}