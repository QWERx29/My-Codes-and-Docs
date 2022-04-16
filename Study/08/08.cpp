#include<bits/stdc++.h>
using namespace std;
void swapp(char &a,char &b)
{
	char t;
	t=a;a=b;b=t;
}
void work(char *st)
{
	int l=strlen(st)-1;
	for(int i=0;i<l/2;++i) swap(st[i],st[l-i-1]);
}
int main()
{
	char s[10086],*str=s;
	cin.getline(s,10086);
	work(str);
	printf("%s",str);
	return 0;
}
