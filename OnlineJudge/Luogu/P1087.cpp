#include<bits/stdc++.h>
using namespace std;
char s[10086];
void fbi(int x,int y)
{
	if(y>x) 
	{
		fbi(x,(x+y)/2);
		fbi((x+y+1)/2,y);
	}
	int B=1,I=1;
	for(int i=0;i<=y-x;i++)
	{
		if(s[x+i]=='1') B=0;
		else if(s[x+i]=='0') I=0;
	}
	if(B) cout<<'B';
	else if(I) cout<<'I';
	else cout<<'F';
}
int main()
{
	int n;
	cin>>n>>s;
	fbi(0,(1<<n)-1);
	return 0;
}
