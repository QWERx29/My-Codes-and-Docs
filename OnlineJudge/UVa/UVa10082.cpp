#include<bits/stdc++.h>
#define N 96110
#define ll long long
char s[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./" ;
using namespace std;
int main()
{
	int i,c;
	ios::sync_with_stdio(false);
 //   freopen("10082.txt","r",stdin);
   // freopen("10082.out","w",stdout);
    
    while((c=getchar())!=EOF)
    {
    	for(i=1;s[i]&&s[i]!=c;i++);
		if(s[i]) putchar(s[i-1]);
		else putchar(c);
	}
	return 0;
}

