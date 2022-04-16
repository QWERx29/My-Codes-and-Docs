#include<bits/stdc++.h>
using namespace std;
char s[100][20],c1,c2;
int n,sum=0,maxa=0,score1,score2,num,a,b,k;
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {                  
		scanf("%s %d %d %c %c %d",&s[i],&score1,&score2,&c1,&c2,&num);
		a=c1=='Y'?1:0;                       
		b=c2=='Y'?1:0;                       
		int tmp=0;
		if((score1>80)&&(num>0)) tmp+=8000;   
		if((score1>85)&&(score2>80)) tmp+=4000; 
		if(score1>90) tmp+=2000;                  
		if(b&&(score1>85)) tmp+=1000;         
		if(a&&(score2>80)) tmp+=850;          
		sum+=tmp;                                         
		if(tmp>maxa) {maxa=tmp;k=i;}              
    }
    printf("%s\n%d\n%d\n",s[k],maxa,sum);
	return 0;
}

