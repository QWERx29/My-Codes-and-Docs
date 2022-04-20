#include<bits/stdc++.h>
#define N 96110
#define ll long long
using namespace std;
int n,cnt,tot;
string s;
int main()
{
//	ios::sync_with_stdio(false);
 //   freopen("1585.txt","r",stdin);
  //  freopen("1585.out","w",stdout);
    cin>>n;
    while(n--)
    {
    	cnt=0;tot=0;
    	cin>>s;
    	for(int i=0;i<s.length();i++)
    	{
    		if(s[i]=='O') cnt++;
    		else if(s[i]=='X') cnt=0;
    		tot+=cnt;
		}
		cout<<tot<<endl;
	}
	return 0;
}

