#include<bits/stdc++.h>
using namespace std;
int sum,d=1,j=1,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum+=d;
        if(j>=d) 
        {
            d++;
            j=1;
        }
        else j++;
    }
    cout<<sum;
    return 0;
}
