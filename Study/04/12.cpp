#include<iostream>
using namespace std;
int main()
{
	for(int i=0;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			for(int u=0;u<=100;u++)
			{
				if((i+j+u==100)&&(5*i+3*j+u/3==100)&&(u%3==0))
					cout<<i<<" "<<j<<" "<<u<<endl;
			}
		}
	} 
	return 0;
}

