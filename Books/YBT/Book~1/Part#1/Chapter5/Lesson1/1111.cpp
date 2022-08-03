#include<bits/stdc++.h>
using namespace std;
int s[8],as[8],maxi=0,maxt=0;
int main()
{
	for(int i=1;i<=7;i++) cin>>s[i]>>as[i];
	for(int i=1;i<=7;i++)
		if(s[i]+as[i]>8&&s[i]+as[i]>maxt) 
        {
            maxi=i;
            maxt=s[i]+as[i];
        }
	cout<<maxi;
}