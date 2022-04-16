    #include<iostream>
    #include<cstdio>
    using namespace std;
    int a[100],b[100],c[100],d[100][100],ans=0,n;
    void print(int q)
    {
    	if(q==1) return;
    	for(int i=2;i<=q;i++)
    	{
    		if(a[i]<a[i-1]) return;
    	}
    	ans++;
    	cout<<n<<"=";
    	cout<<a[1];
    	for(int i=2;i<=q;i++)
    	{
    		if(a[i]!=0)
    		{
    			cout<<'+'<<a[i];
    		}
    	}
    	cout<<endl;
    }
    void ba(int k,int q)
    {
    	for(int i=1;i<=k;i++)
    	{
    		a[q]=i;
    		if(k-i==0) print(q);
    		else ba(k-i,q+1);
    	}
    }
    int main()
    {
    	cin>>n;
    	ba(n,1);
    	//cout<<"total="<<ans;
    }
