#include <bits/stdc++.h>
struct node{ int map[5][5],wi,wj,t; } f[1000001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int xd[5][5];
int nz[5][5];
int zp(int head)
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(f[head].map[i][j]!=xd[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool pdc(int tail)
{
    for(int i=1;i<=tail;i++)
    {
        bool flag=true;
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                if(f[i].map[j][k]!=nz[j][k])
                {
                    flag=false;
                    break;
                }
            }
            if(flag==false)
            {
                break;
            }
        }
        if(flag==true)
        {
            return false;
        }
    }
    return true;
}
void bfs()
{
    int head=1,tail=2;
    while(head<tail)
    {
        if(zp(head)==true)
        {
            printf("%d",f[head].t);
            return ;
        }
        for(int i=0;i<=3;i++)
        {
            int nx=f[head].wi+dx[i];
            int ny=f[head].wj+dy[i];
            if(nx>=1 && nx<=3 && ny>=1 && ny<=3)
            {
                memset(nz,0,sizeof(nz));
                for(int j=1;j<=3;j++)
                {
                    for(int k=1;k<=3;k++)
                    {
                        nz[j][k]=f[head].map[j][k];
                    }
                }
                nz[f[head].wi][f[head].wj]=f[head].map[nx][ny];
                nz[nx][ny]=0;
                if(pdc(tail)==true)
                {
                    for(int j=1;j<=3;j++)
                    {
                        for(int k=1;k<=3;k++)
                        {
                            f[tail].map[j][k]=nz[j][k];
                        }
                    }
                    f[tail].t=f[head].t+1;
                    f[tail].wi=nx;
                    f[tail].wj=ny;
                    tail++;
                }
            }
        }
        head++;
    }
}
int main()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            scanf("%d",&f[1].map[i][j]);
            if(f[1].map[i][j]==0)
            {
                f[1].t=0;
                f[1].wi=i;
                f[1].wj=j;
            }
        }
    }
    for(int i=1;i<=3;i++)
    {
    	for(int j=1;j<=3;j++) scanf("%d",&xd[i][j]);
	}
    bfs();
    return 0;
}
