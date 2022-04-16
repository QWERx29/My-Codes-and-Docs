#include<bits/stdc++.h>
using namespace std;
char ch[6]={'A','B','C','D','E','F'};
void turn(int n,int w)
{
	int x[17],i,j,k=0;
    if(n<0) cout<<'-';      
    j=abs(n);
    do
	{
		k++;    
        i=j%w;
        j/=w;
        x[k]=i;
    }while (j!=0);
    for (int h=k; h>=1; --h)
    if (x[h]<10) cout<<x[h];
    else  cout<<ch[x[h]-10];
    cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	turn(n,2);
	turn(n,8);
	turn(n,16);
	return 0;
}

