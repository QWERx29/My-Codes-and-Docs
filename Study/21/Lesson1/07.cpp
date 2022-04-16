#include<bits/stdc++.h>
using namespace std;
string s1,s2;
void f(int l1,int r1,int l2,int r2)
{
    int i,j;
    for(i=l2;i<=r2;i++)
	{
        int t=0;
        for(j=l1;j<=r1;j++)
		{
            if(s2[i]==s1[j])
			{
                cout<<s1[j];
                t=1;
                break;
            }
        }
        if(t) break;
 
    }
    if(j>l1) f(l1,j-1,0,r2);
    if(j<r1) f(j+1,r1,0,r2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>s1>>s2;
    f(0,s1.size()-1,0,s2.size()-1);
    return 0;
}
