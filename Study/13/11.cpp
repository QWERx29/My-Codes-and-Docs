#include<bits/stdc++.h>
using namespace std;
int n,c,s[10086],s1[10086],m,q,k;
bool flag=false;
void search(int t)
{
	if(flag==true) return ;
	q+=s[t];
    s1[k++]=s[t];
    if(q>c) return ;
    if(q==c) { flag=true; return ;}
    for(int j=t+1;j<=n;j++)
	{
        search(j);
        if(flag==false)
		{
            q-=s[j];
            k--;
        }
    }
	
}
int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i];
		m+=s[i];
	}
	if(m<c)
	{
		cout<<"No Solution!";
		return 0;
	}
	search(1);
	if(flag==true)
	{
		for(int i=0;i<k;i++) cout<<s1[i]<<" ";
	}
	else cout<<"No Solution!";
	return 0;
}
