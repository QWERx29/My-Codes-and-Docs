#include <bits/stdc++.h>
using namespace std;
int a,b,c,cnt;
int main()
{
    
    cin>>a>>b>>c;
    for(int x=0;x<=c;x++)
    {
        for(int y=0;y<=c;y++)
        {
            if(a*x+b*y==c) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

