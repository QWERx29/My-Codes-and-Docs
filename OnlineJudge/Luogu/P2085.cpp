#include<bits/stdc++.h>
using namespace std;
int heap[10005];
int heap_size,n,m,a,b,c;
void put(int x)
{
    heap[++heap_size]=x;
    push_heap(heap+1,heap+1+heap_size);
}
int get()
{
    pop_heap(heap+1,heap+1+heap_size);
    return heap[heap_size--];
}
int f(int a,int b,int c,int i)
{
    return a*i*i+b*i+c;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;  
    cin>>a>>b>>c;
    for(int i=1;i<=m;i++) put(f(a,b,c,i));
    for(int i=2;i<=n;i++)
	{
        cin>>a>>b>>c;
        for(int j=1;j<=m;j++)
		{
            if(f(a,b,c,j)<heap[1])
			{
                get();
                put(f(a,b,c,j));
            }
        }
    }
    int s[10000];
    for(int i=0;i<m;i++) s[i]=get();
    for(int i=m-1;i>=0;i--) printf("%d ",s[i]);
    return 0;
}
