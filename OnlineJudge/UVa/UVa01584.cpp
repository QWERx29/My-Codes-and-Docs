#include<cstdio>
#include<cstring>
#define N 96110
#define ll long long
using namespace std;
int less(const char* s,int p,int q) 
{
	int n=strlen(s);
	for(int i=0;i<n;i++)
	if(s[(p+i)%n] != s[(q+i)%n])
		return s[(p+i)%n]<s[(q+i)%n];
	return 0;
}
int main()
{
//    freopen("1584.txt","r",stdin);
//    freopen("1584.out","w",stdout);
    int T;
	char s[N];
	scanf("%d", &T);
	while(T--) 
	{
		scanf("%s",s);
		int ans=0;
		int n=strlen(s);
		for(int i=1;i<n;i++)
			if(less(s,i,ans)) ans = i;
		for(int i=0;i<n;i++)
			putchar(s[(i+ans)%n]);
		putchar('\n');
	}
	return 0;
}

