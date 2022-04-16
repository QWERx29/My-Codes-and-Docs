#include<stdio.h>  
#include <string.h>  
  
#define M 40  

/*
题目大意：

将从1到n这n个整数围成一个圆环，若其中任意2个相邻的数字相加，结果均为素数，那么这个环就成为素数环。

要求输出：从整数1开始。

分析问题，可以构造解空间树，比较顺利的想到 DFS 、回溯。*/

int isPrime[M];////素数表,下标为素数的置为1,否则0  
int vis[M>>1];// vis 标识 1-n,是否被选  
int res[M>>1];// 存储解向量  
  
int cnt;// 测试样例个数  
  
void prime()//求出1-40的所有素数  
{  
    int i, j;  
    for(i=1; i<M; ++i)  
    {  
        int ok = 1; 
        //求素数 
        for(j=2; j*j<=i; ++j)  
        {  
            if(i%j == 0)  
            {  
                ok = 0;  
                break;  
            }  
        }  
        if(ok)  
            isPrime[i]=1; //小标为素数
  
    }  
}  
  
void dfs(int cur, int n)  
{  
    int i;  
    if(cur == n && isPrime[res[n-1] + res[0]])//别忘了测试边界，最后一个和第一个数 构成的环  
    {  
        for(i=0; i<n-1; ++i)  
            printf("%d ", res[i]);  
        printf("%d\n", res[i]);  
    }  
    else  
    {  
        for(i=2; i<=n; i++)// 尝试每个i, 1始终在排头,因此从2开始计算  
        {  
            if(!vis[i] && isPrime[res[cur-1] + i])// i未用过且和前一个数和为素数  
            {  
                res[cur] = i;  
                vis[i] = 1; // 设置标志  
                dfs(cur+1, n);  
                vis[i] = 0; // 回溯, 清除标识  
            }  
        }  
    }  
}  
  
  
int main()  
{  
    
    prime();  
   int n0=6;
        memset(vis, 0, sizeof(vis));  
        res[0] = 1;  
        dfs(1, n0);  
        printf("\n");  
     
    return 0;  
}
