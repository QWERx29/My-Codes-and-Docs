#include <bits/stdc++.h>
using namespace std;
void turn(int n,int w) 
{
    int x[17],i,j,k=0;
    if(n<0)
        cout<<'-';
    j=abs(n);
    do 
	{
        k++;
        i=j%w;
        j/=w;
        x[k]=i;
    } while (j!=0);
    for (int h=k; h>=1; --h)
    {
    	cout<<x[h];
	}
    cout<<endl;
}
int main() 
{
    int n;
    cin>>n;
    turn(n,8);
    return 0;
}
