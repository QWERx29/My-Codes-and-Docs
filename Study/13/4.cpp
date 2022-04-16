#include<bits/stdc++.h>
using namespace std;
bool b[100]={0},d[100]={0},c[100]={0};
int tot=0,a[101]={0},n;

void search(int i)
{
	int j;
	for(j=1;j<=n;j++)
	{
		if((!b[j])&&(!c[i+j])&&(!d[i-j+7]))
		{
			a[i]=j;
			b[j]=1;
			c[i+j]=1;
			d[i-j+7]=1;
			if(i==n)
			{
				tot++;
				for(int q=1;q<=n;q++) cout<<setw(5)<<a[q];
				cout<<endl;
			} 
			else search(i+1);
			b[j]=0;
			c[i+j]=0;
			d[i-j+7]=0;
		} 
	}
}

int main()
{
	cin>>n;
	search(1);
	if(tot==0) cout<<"no solute!";
	//cout<<tot;
	return 0;
}
