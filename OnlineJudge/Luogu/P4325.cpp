// luogu-judger-enable-o2
#include <stdio.h>
#include <stdlib.h>
#define N 10
int temp[1000];
int num[11];
int i,j,ans=0,c;
int main()
{
    for(i=0;i<N;i++)
        scanf("%d",&num[i]);
    for(j=0;j<N;j++)
    {
        c=num[j]%42;
        temp[c]++;          
    }
    for(i=0;i<42;i++)
    {
        if(temp[i]!=0)      
          ans++;
    }
    printf("%d",ans);
 
    return 0;
}
