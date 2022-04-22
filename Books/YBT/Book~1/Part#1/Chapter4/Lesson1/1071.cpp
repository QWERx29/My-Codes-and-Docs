#include<bits/stdc++.h>
using namespace std;
int n,a=1,b=1,c;
int main()
{
    cin>>n;
    if(n<=2)
    {
        cout<<1;
        return 0;
    }
    else 
    {
        for(int i=3;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        cout<<c;
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
    cin>>t;
    {
        for(int i=1;i<=t;i++)
        {
            int a=1,b=1,c=0;
            cin>>n;
            if(n<=2)
            {
                cout<<1<<endl;
            }
            else 
            {
                for(int i=3;i<=n;i++)
                {
                    c=a+b;
                    a=b;
                    b=c;
                }
                cout<<c<<endl;
            }
        }
    }
    return 0;
}
*/