// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
char s[4][100],f[400][52];
int b[26],maxa,len[4];
int main()
{
	memset(f,' ',sizeof(f));
	for(int i=0;i<4;i++)
	{
		gets(s[i]);
		len[i]=strlen(s[i]);
		for(int j=0;j<len[i];j++)
		{
			if(s[i][j]>='A'&&s[i][j]<='Z') b[s[i][j]-65]++;
		}
	}
	for(int i=0;i<26;i++) if(b[i]>=maxa) maxa=b[i];
	for(int i=0;i<26;i++)
	{
		for(int j=b[i];j>0;j--)
		f[maxa-j][2*i]='*';
	}
	for(int j=0;j<maxa;j++)
	{
		for(int i=0;i<52;i++) cout<<f[j][i];
		cout<<endl;
	}
	for(int i=0;i<26;i++)
		cout<<(char)(i+65)<<' ';
}
