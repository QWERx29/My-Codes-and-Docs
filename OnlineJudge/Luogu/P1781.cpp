// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,num;
	string tic;
	string max="";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tic;
        if(tic.size()>max.size()||(tic.size()==max.size()&&tic.compare(max)>0))
		{
            max=tic;
            num=i;
        }
        else continue;
    }
    cout<<num<<endl<<max<<endl;
}
