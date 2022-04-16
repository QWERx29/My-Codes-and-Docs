/*#include<bits/stdc++.h>
using namespace std;
char st[1010],a,b;
int main()
{
	int n=0,i;
	while((st[n++]=getchar())!='\n')
	a=getchar();getchar();b=getchar();
	for(i=0;i<n;i++)
		if (st[i]==a) cout<<b;
	  	else cout<<st[i];
	cout<<endl;
	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
char st[1005],m,n; 
int main()
{
	cin>>st;
	cin>>m>>n;
	for(int i=0;i<strlen(st);i++)
	{
		if(st[i]==m) st[i]=n;
	}
	cout<<st;
	return 0;
}
