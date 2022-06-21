#include<bits/stdc++.h>
using namespace std;
typedef struct n
{
    int num,ord;
}node;
node first[100010],second[100010];
int a[100010],b[100010],ans;
int compare(node x,node y)
{
    return x.num<y.num;
}
void merge(int l,int r)
{
    if(l>=r) return ;
    int mid=(l+r)/2;
    merge(l,mid);
    merge(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]>a[j])
        {
            b[k++]=a[j++];
            ans+=mid-i+1;
            ans%=99999997;
        }
        else b[k++]=a[i++];
    }
    while(i<=mid) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    for(int i=l;i<=r;i++)
        a[i]=b[i];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>first[i].num;
        first[i].ord=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>second[i].num;
        second[i].ord=i;
    }
    sort(first+1,first+n+1,compare);
    sort(second+1,second+n+1,compare);
    for(int i=1;i<=n;i++)
        a[first[i].ord]=second[i].ord;
    merge(1,n);
    cout<<ans;
    return 0;
}