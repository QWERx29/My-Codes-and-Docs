// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int x,z[301];
void jz(int a,int b)
{
    int q=0;
	while(a!=0)
	{
		z[++q]=a%b;
		a/=b;
    }
    z[0]=q;
}
bool hws()
{
    for(int i=1;i<=z[0];i++)
        if(z[i]!=z[z[0]+1-i]) return false;
		return true;
}
void print()
{
    for(int i=z[0];i>=1;i--)
    {
        if(z[i]<=9) cout<<z[i];
        else cout<<char(z[i]-10+'A');
	}
	 
}
int main()
{
	cin>>x;
	for(int i=1;i<=300;i++)
	{
		jz(i*i,x);
		if(hws()==true)
		{
			jz(i,x);print();
			cout<<" ";
			jz(i*i,x);print();
			cout<<endl;
        }
    }
}
