#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    double d=b*b-4*a*c;
    double x1,x2;
    if(d>=0)
    {
        x1=(sqrt(d)-b)/(2*a);
        x2=(-sqrt(d)-b)/(2*a);
    }
    else
    {
        cout<<"No answer!";
        return 0;
    }
    if(d==0) printf("x1=x2=%.5lf",x1);
    else 
    {
        if(x1<x2) printf("x1=%.5lf;x2=%.5lf",x1,x2);
        else printf("x1=%.5lf;x2=%.5lf",x2,x1);
    }
    return 0;
}