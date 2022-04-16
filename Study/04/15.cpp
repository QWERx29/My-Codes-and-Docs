#include<iostream>
using namespace std;
int main()
{
	for(int i=32;i<=100;i++)
	{
		int x=i*i;
		int h,l;
		h=x/100;l=x%100;
		if(h%11==0&&l%11==0) cout<<x<<endl;
	}
	
	return 0;
}
