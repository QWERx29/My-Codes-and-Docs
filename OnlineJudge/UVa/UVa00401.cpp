#include<bits/stdc++.h>
#define N 96110
#define ll long long
using namespace std;
const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[]={"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};
char r(char ch)
{
	if(isalpha(ch)) return rev[ch-'A'];
	return rev[ch-'0'+25];
}
int main()
{
	ios::sync_with_stdio(false);
//  freopen("401.txt","r",stdin);
//  freopen("401.out","w",stdout);
    char s[30];
    while(scanf("%s",s)==1)
    {
    	int len=strlen(s),p=1,m=1;
    	for(int i=0;i<len;i++)
    	{
    		if(s[i]!=s[len-1-i]) p=0;
    		if(r(s[i])!=s[len-1-i]) m=0;
		}
		printf("%s -- is %s.\n\n",s,msg[m*2+p]);
	}
	return 0;
}

