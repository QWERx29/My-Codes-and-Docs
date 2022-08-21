#include<bits/stdc++.h>
#define ll long long 
#define int long long 
using namespace std;
const int N=1e6+5;
const ll MOD=999997;

struct HashTable{
	struct node{
		ll nxt,val,key;
	}data[N];
	ll head[MOD],size=0;
	ll f(int key) { return (key%MOD+MOD)%MOD; }
	inline ll get(int key)
	{
		for(int p=head[f(key)];p;p=data[p].nxt)
			if(data[p].key==key) return data[p].val;
		return 0;
	}
	inline ll modify(int key,int val)
	{
		for(int p=head[f(key)];p;p=data[p].nxt)
			if(data[p].key==key) data[p].val=val;
		return 0;
	}
	inline ll add(int key,int val)
	{
		if(get(key)!=0) 
		{
			modify(key,val);
			return 0;
		}
		data[++size]=(node){head[f(key)],val,key};
		head[f(key)]=size;
		return val;
	}
}h;

signed main()
{
	ios::sync_with_stdio(false);
	ll n,op,key,val;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>op>>key;
		if(op==1)
		{
			cin>>val;
			h.add(key,val);
		}
		if(op==2)
			cout<<h.get(key)<<endl;
	}
	return 0;
}