#include<bits/stdc++.h> 
#define N 501
using namespace std;
int g[N][N],pre[N];
int main()
{
    int n,j;
    cin>>n;
    for(int i=1;i<=n;i++)
        while(scanf("%d",&j)!=EOF && j)
            g[i][j]=1;
    
    for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++)
            for(int j=1;j<=n;j++)
                if(g[i][k]&&g[k][j])
                    g[i][j]=1;
    for(int i=1;i<=n;i++)
        pre[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(g[i][j])
                pre[j]=pre[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(pre[i]==i)
            cnt++;
    cout<<cnt<<endl;
    return 0;
}
