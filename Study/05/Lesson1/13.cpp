#include<bits/stdc++.h>
using namespace std;
char a[105],ch;
int i,j=1;
int main()
{
	cin>>ch;
	while(ch!='.')
    {
      ++i;
      a[i]=ch;
      cin>>ch;
    }
	while((j<i)&&(a[j]==a[i]))		
    {
        --i; 
		++j;
    }
    if(j>=i) cout<<"Yes"<<endl;
    else   cout<<"No"<<endl;
	return 0;
}

