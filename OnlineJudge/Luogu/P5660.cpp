#include<bits/stdc++.h>
using namespace std;
int main()
{
 	char s[110];
 	int ans=0;
 	scanf("%s",s);
 	for(int i=0;i<strlen(s);i++)
 		if(s[i]=='1') ans++;
	cout<<ans;
	return 0;
}

