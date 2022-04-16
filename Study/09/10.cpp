#include<bits/stdc++.h>
using namespace std;
char c[109];
int k,l,u;
struct big
{
	int a[109];
}d,p,q,r,s,t;
big mul(big x,big y)
{
	big z=d;
	register int i,j;
	for(i=1;i<=k;++i)
	{
		for(j=k-i+1;j;--j)
		{
			z.a[i+j-1]+=x.a[i]*y.a[j];
		}
	}
	for(i=1;i<k;++i) z.a[i+1]+=z.a[i]/10,z.a[i]%=10;
	z.a[k]%=10;
	return z;
}
int main()
{
	register int i,j;
	scanf("%s%d",c,&k),l=strlen(c);
	for(i=(l<k?l:k);i;--i)p.a[i]=c[l-i]-48;
	r=p,t.a[l=1]=1;
	for(i=1;i<=k;++i){
		if(mul(p,r).a[i]==p.a[i])continue;
		u=1,s=r;
		do
		{
			r=mul(s,r),++u;
			if(u>10){
				puts("-1");
				return 0;
			}
		}while(mul(p,r).a[i]!=p.a[i]);
		for(j=1;j<=l;++j) t.a[j]*=u;
		for(j=1;j<l;++j) t.a[j+1]+=t.a[j]/10,t.a[j]%=10;
		if(t.a[l]>=10) t.a[l+1]+=t.a[l]/10,t.a[l++]%=10;
	}
	for(i=l;i;--i) printf("%d",t.a[i]);
}

