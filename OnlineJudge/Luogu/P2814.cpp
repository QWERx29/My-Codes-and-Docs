#include<bits/stdc++.h>
const int N=96110;
int f[N],num[N];
char name[N][10];
int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
int main()
{
    char ch;
    int i,t,n=0,tn,j;
    for(i=1;i<=N;i++) f[i]=i;
    scanf("%c",&ch);
    while(ch!='$')
    {
    	int fnum;
        scanf("%s",name[++n]+1);
        num[n]=n,tn=n;
        for(i=1;i<n;i++)
        {
        	for(j=1;j<=6;j++)
        	{
        		if(name[i][j]!=name[n][j]) break;
			}
			if(j>6)
			{
				tn=i;
				break;
			}
		}
        if(ch=='#') fnum=num[tn];
        else if(ch=='+') f[find(num[tn])]=find(fnum);
        else
        {
            printf("%s",name[tn]+1);
            printf(" ");
            int fn=find(num[tn]);
            printf("%s",name[fn]+1);
            printf("\n");
        }
        scanf("\n%c",&ch);
    }
    return 0;
}
