#include<bits/stdc++.h>
using namespace std;
bool isPrime(int a)
{
    if(a==2) return true;
    if(a%2==0) return false;
    else
    {
        for(int i=3;i*i<=a;i+=2)
        {
            if(a%i==0) return false;
        }
    }
    return true;
}
int n,c=0;
int main()
{
    cin>>n;
    for(int i=2;;i++)
    {
        if(isPrime(i))
        {
            c++;
            if(c>=n)
            {
                cout<<i;
                return 0;
            }
        }
    }
}