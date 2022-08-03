#include<bits/stdc++.h>
using namespace std;
int n;
string player1,player2;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>player1>>player2;
		if(player1==player2)
			cout<<"Tie"<<endl;
		else if((player1=="Rock"&&player2=="Scissors")||(player1=="Scissors"&&player2=="Paper")||(player1=="Paper"&&player2=="Rock"))
			cout<<"Player1"<<endl;
		else
			cout<<"Player2"<<endl;
	}
	return 0;
}