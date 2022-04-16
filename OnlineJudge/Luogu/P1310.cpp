#include<bits/stdc++.h>
using namespace std;
int n,q[100086],w[100086],top,k;
char c[100086],s[100086],ans[961100];
int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	ans[++k]='.';
	for(int i=0;c[i];i++)
	{
		if(c[i]=='('||c[i]=='*')
            s[++top]=c[i];
        if(c[i]=='+')
        {
            while(s[top]=='*')
                ans[++k]=s[top--];
            s[++top]=c[i];
        }
        if(c[i]==')')
        {
            while(s[top]!='(')
                ans[++k]=s[top--];
            top--;
        }
        if(c[i]!='('&&c[i]!=')')
            ans[++k]='.';
	}
	while(top>0)
		ans[++k]=s[top--];
	for(int i=1;i<=k;i++)
	{
		if(ans[i]=='.')
		{
			q[++top]=1;
			w[top]=1;
		}
		if(ans[i]=='*')
		{
			top--;
			q[top]=(q[top+1]*w[top]+q[top]*w[top+1]+q[top]*q[top+1])%10007;
			w[top]=w[top]*w[top+1]%10007;
		}
		if(ans[i]=='+')
        {
            top--;
            w[top]=(q[top+1]*w[top]+q[top]*w[top+1]+w[top]*w[top+1])%10007;
            q[top]=q[top]*q[top+1]%10007;
        }
	}
	cout<<q[1];
	return 0;
}

