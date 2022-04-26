#include<iostream>
using namespace std;
int main()
{
	int i;
	for(i=1;;i++)
	{
		if((60*i+1)%7==0)
		{
			cout<<60*i+1;break;
		}
	} 
	return 0;
}

