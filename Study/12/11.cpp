#include<bits/stdc++.h>
using namespace std;
void H(int n,char a,char b,char c)
{
    if(n>0)
    {
        H(n-1,a,c,b);  
        cout<<n<<" "<<a<<" "<<c<< endl;  
        H(n-1,b,a,c); 
    }
} 
int main()
{
	int n;
	cin>>n;
	H(n,'A','C','B');
	return 0;
}

