#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,i,j;
	cin>>N>>i>>j;
	for(int m=1;m<=N;m++)
		printf("(%d,%d) ",i,m);
	cout<<endl;
	for(int m=1;m<=N;m++)
		printf("(%d,%d) ",m,j);
	cout<<endl;
	for(int m=1;m<=N;m++)
	{
		for(int n=1;n<=N;n++)
            if((m-i)==(n-j)) printf("(%d,%d) ",m,n);
	}
	cout<<endl;
	for(int m=N;m>=1;m--)
	{
		for(int n=N;n>=1;n--)
            if((m-i)==-(n-j)) printf("(%d,%d) ",m,n);
	}
	cout<<endl;
	return 0;
}
