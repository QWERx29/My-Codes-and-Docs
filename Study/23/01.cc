#include<bits/stdc++.h>
using namespace std;
const int N=512;
char s[N],p[N];
int a,b,ans,t=1;
int bf(char s[],char p[],int start)
{
	int i=start,j=1;
	while(i<=a&&j<=b)
	{
		if(s[i]==p[j]) {i++,j++;}
		else {i=i-j+2,j=1;}
	}
	if(j>b) return i-b;
	else return 0;
}
int main()
{
	cin>>a>>b;
	for(int i=1;i<=a;i++) cin>>s[i];
	for(int i=1;i<=b;i++) cin>>p[i];
	for(int i=1;i<=a;i++)
	{
		int w=bf(s,p,i);
		if(w!=0) 
		{
			ans++;
			i=w;
		}
	}
	if(ans==0) cout<<"Substring Not Found";
	else cout<<ans;
	return 0;
}