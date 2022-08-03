#include<bits/stdc++.h>
using namespace std;

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
int kmp(char s[],char p[])
{
	//if(strlen(s)==0||strlen(p)==0||strcmp(s,p)<0) return 0;
	int i=0,j=0;
	int nxt[301050];
	get_next(p,nxt);
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
	char s[301050],p[301050];
	cin>>s>>p;
	cout<<kmp(s,p)+1;
	return 0;
}