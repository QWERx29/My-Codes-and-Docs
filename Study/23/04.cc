#include<bits/stdc++.h>
using namespace std;
int nxt[61050];
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
	char s[61050],p[61050];

    int ans=0,t;
    cin>>s>>p;
    get_next(p,nxt);
	for(int i=0;i<strlen(s);i++)
    {
        t=kmp(s,p,i);
        if(t>=0) {ans++;i=t;}
    }
    cout<<ans;
	return 0;
}