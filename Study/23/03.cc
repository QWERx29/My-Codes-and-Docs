#include<bits/stdc++.h>
using namespace std;
int nxt[31050];
void get_next(char p[],int nxt[])
{
	int j=2,k=0;
	nxt[0]=-1;
	if(strlen(p)==1) return ;
	nxt[1]=0;
	while(j<strlen(p))
	{
		if(p[j-1]==p[k]) nxt[j++]=++k;
		else if(k==0) nxt[j++]=0;
		else k=nxt[k];
	}
}
int kmp(char s[],char p[],int start)
{
	int i=start,j=0;
	//int nxt[31050];
	//get_next(p,nxt);
	while(i<strlen(s)&&j<strlen(p))
	{
		if(s[i]==p[j]) {i++;j++;}
		else if(nxt[j]==-1) i++;
		else j=nxt[j];
	}
	if(j==strlen(p)) return i-j;
	else return -1;
}
int main()
{
	char s[31050],p[31050];

    int a,b,ans=0,t;
    cin>>a>>b;
    for(int i=0;i<a;i++) cin>>s[i];
    for(int i=0;i<b;i++) cin>>p[i];
    get_next(p,nxt);
	for(int i=0;i<a;i++)
    {
        t=kmp(s,p,i);
        if(t>=0) {ans++;i=t;}
    }
    if(ans!=0) cout<<ans;
    else cout<<"Substring Not Found";
	return 0;
}