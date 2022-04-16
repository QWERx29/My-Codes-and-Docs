#include<bits/stdc++.h>
using namespace std;
struct node{
    int d;
    int left;
    int right;
}q[10086];
int n,a;
int ans;
void inorder(int k)
{
    if(q[k].left)
        inorder(q[k].left);
    ans++;
    if(q[k].d==a)
    {
        cout<<ans<<endl;
        exit(0);
    }
    if(q[k].right)
        inorder(q[k].right);
}
int main()
{
    cin>>n>>a;
    for(int i=1;i<=n;i++)
        cin>>q[i].d>>q[i].left>>q[i].right;
    inorder(1);
    return 0;
}
