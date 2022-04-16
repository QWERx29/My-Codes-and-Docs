#include<bits/stdc++.h>
using namespace std;
int heap_size=0,x,n;
int heap[1000860]={0};
void put(int x)
{
    heap[++heap_size]=x;
    push_heap(heap+1,heap+1+heap_size,greater<int>());  
}
int get()
{    
    return heap[1];   
}
void del()
{ 
    pop_heap(heap+1,heap+1+heap_size,greater<int>());  
    heap_size--;    
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        cin>>x;
        if(x==1) {cin>>x;put(x);}
        else if(x==2) {cout<<get()<<endl;}
        else if(x==3) del();      
    }
}
