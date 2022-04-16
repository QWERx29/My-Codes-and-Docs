// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
char a[20],b[20];
int c=1,d=1;
int main()
{
	gets(a);
	gets(b);
	for(int i=0;i<strlen(a);i++) c*=(int(a[i])-64);
	for(int j=0;j<strlen(b);j++) d*=(int(b[j])-64);
	if(c%47==d%47) cout<<"GO";
	else cout<<"STAY";
}
