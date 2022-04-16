#include <iostream>
int a,b,c,d,n;
using namespace std;
int main() 
{
    cin>>n;
    if(n%2==0&&n>4&&n<=12) a=1;
	if(n%2==0||n>4&&n<=12||n%2==0&&n>4&&n<=12) b=1;
	if(n%2==0&&n<=4&&n>12||n>4&&n<=12&&n%2==1) c=1;
	if(n%2==1&&n<=4||n%2==1&&n>12) d=1;
	cout<<a<<" "<<b<<" "<<c<<" "<<d;
    return 0;
}
