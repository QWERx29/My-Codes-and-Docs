#include<bits/stdc++.h>
using namespace std;
int m,n,t1,t2,r[256],s[10086],f;
char a[10086],s1[10086];
void out(char c)
{
	if(c=='+') s[--t1]+=s[t1+1];
	else if(c=='-') s[--t1]-=s[t1+1];
	else if(c=='*') s[--t1]*=s[t1+1];
	else if(c=='/') s[--t1]/=s[t1+1];
} 
int main()
{
	cin>>a;
	r['+']=r['-']=1;
	r['*']=r['/']=2;
	if(r[a[0]]) f=1;
	int i=0;
	while(a[i]!='\0') {
        if(a[i]>='0'&&a[i]<='9') 
		{
            int x=0;
            while(a[i]>='0'&&a[i]<='9') 
			{
                x=x*10+a[i]-'0';
                i++;
            }
            s[++t1]=x;
        }
        if(a[i]=='(') 
		{
            s1[++t2]='(';
            m++;
        }
        if(a[i]==')') {
            n++;
            while(s1[t2]!='(') 
			{
                out(s1[t2]);
                t2--;
            }
            t2--;
        }
        if(r[a[i]]&&r[a[i+1]]) f=1;
        if(r[a[i]]) {
            while(r[a[i]]<=r[s1[t2]]) 
			{
                out(s1[t2]);
                t2--;
            }
            t2++;
            s1[t2]=a[i];
        }
        i++;
        if(f) 
		{
            printf("NO");
            return 0;
        }
    }
	while(t2!=0)
	{
		out(s1[t2]);
		t2--;
	}
	if(m!=n) 
	{
		cout<<"No";
		return 0;
	}
	cout<<s[t1];
	return 0;
}

