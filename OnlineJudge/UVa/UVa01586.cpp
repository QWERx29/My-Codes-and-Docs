#include<bits/stdc++.h>
#define N 96110
#define ll long long
using namespace std;
int n,x,i,j;
string s;
double mol(char c)
{
	if(c=='C') return 12.01;
	if(c=='H') return 1.008;
	if(c=='O') return 16.00;
	if(c=='N') return 14.01;
}
bool isnum(char c)
{
	if(c>='0'&&c<='9') return true;
	else return false;
}
double ans;
int main()
{
	ios::sync_with_stdio(false);
  //  freopen("1586.txt","r",stdin);
  //  freopen("1586.out","w",stdout);
    cin>>n;
    while(n--)
    {
    	cin>>s;
    	ans=0;
    	for(i=0;i<s.length();i++)
    	{
    		if(isnum(s[i])) continue;
    		if(!isnum(s[i+1])) ans+=mol(s[i]);
    		else
    		{
    			x=0;
    			for (int j=i+1;isnum(s[j]);j++) x=x*10+(s[j]-'0');
                ans+=mol(s[i])*x;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}

