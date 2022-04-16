#include<cstdio>
using namespace std;
int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	int a[n+1],j=n,k=1,p=0;
	for (int i=1;i<n;i++) a[i]=i+1;
  	a[n]=1; 
  	while (p<n)          
  	{
    	while(k<m)        
    	{
     	 j=a[j];
    	  k++;
   		}                    
    printf("%d ",a[j]); p++;   
    a[j]=a[a[j]]; k=1;
  	}                 
  	return 0;
}
